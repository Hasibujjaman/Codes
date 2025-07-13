########################## 1 - Import Packages ################################
"""
We'll make use of the following packages:

numpy is a package for scientific computing in python.
deque will be our data structure for our memory buffer.
namedtuple will be used to store the experience tuples.
The gym toolkit is a collection of environments that can be used to test reinforcement learning algorithms. We should note that in this notebook we are using gym version 0.24.0.
PIL.Image and pyvirtualdisplay are needed to render the Lunar Lander environment.
We will use several modules from the tensorflow.keras framework for building deep learning models.
utils is a module that contains helper functions for this assignment. You do not need to modify the code in this file.
"""
import time
from collections import deque, namedtuple

import gym
import numpy as np
import PIL.Image
import tensorflow as tf
import utils2

from pyvirtualdisplay import Display
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense, Input
from tensorflow.keras.losses import MSE
from tensorflow.keras.optimizers import Adam


# Set up a virtual display to render the Lunar Lander environment.
Display(visible=0, size=(840, 480)).start();

# Set the random seed for TensorFlow
tf.random.set_seed(utils2.SEED)






########################## 2 - Hyperparameters ################################

MEMORY_SIZE = 100_000     # size of memory buffer
GAMMA = 0.995             # discount factor
ALPHA = 1e-3              # learning rate  
NUM_STEPS_FOR_UPDATE = 4  # perform a learning update every C time steps. (at each time step t, the agent moves from one state to another)









########################## 3 - The Lunar Lander Environment ########################
"""
In this notebook we will be using OpenAI's Gym Library. The Gym library provides a wide variety of environments for reinforcement learning. 
To put it simply, an environment represents a problem or task to be solved. In this notebook, we will try to solve the Lunar Lander environment using reinforcement learning.

The goal of the Lunar Lander environment is to land the lunar lander safely on the landing pad on the surface of the moon. 
The landing pad is designated by two flag poles and its center is at coordinates (0,0) but the lander is also allowed 
to land outside of the landing pad. The lander starts at the top center of the environment with a random initial force 
applied to its center of mass and has infinite fuel. The environment is considered solved if you get 200 points.
"""
############### 3.1 Action Space ###############
"""
The agent has four discrete actions available:

    Do nothing.
    Fire right engine.
    Fire main engine.
    Fire left engine.

Each action has a corresponding numerical value:

    Do nothing = 0
    Fire right engine = 1
    Fire main engine = 2
    Fire left engine = 3
"""

############### 3.2 Observation Space ###############
"""
The agent's observation space consists of a state vector with 8 variables:

    Its  (x,y) coordinates. The landing pad is always at coordinates  (0,0).
    Its linear velocities  (𝑥˙,𝑦˙).
    Its angle  𝜃.
    Its angular velocity  𝜃˙.
    Two booleans,  l and  r, that represent whether each leg is in contact with the ground or not.
"""

############### 3.3 Rewards ###############
"""
After every step, a reward is granted. The total reward of an episode is the sum of the rewards for all the steps within that episode.

For each step, the reward:

    is increased/decreased the closer/further the lander is to the landing pad.
    is increased/decreased the slower/faster the lander is moving.
    is decreased the more the lander is tilted (angle not horizontal).
    is increased by 10 points for each leg that is in contact with the ground.
    is decreased by 0.03 points each frame a side engine is firing.
    is decreased by 0.3 points each frame the main engine is firing.

The episode receives an additional reward of -100 or +100 points for crashing or landing safely respectively.
"""

############### 3.4 Episode Termination ###############
"""
An episode ends (i.e the environment enters a terminal state) if:

    The lunar lander crashes (i.e if the body of the lunar lander comes in contact with the surface of the moon).

    The absolute value of the lander's  x-coordinate is greater than 1 (i.e. it goes beyond the left or right border)
"""







########################## 4 - Load the Environment ########################
"""
We start by loading the LunarLander-v2 environment from the gym library by using the .make() method. 
LunarLander-v2 is the latest version of the Lunar Lander environment and you can read about its version history in the Open AI Gym documentation.
"""
env = gym.make('LunarLander-v2')

"""
Once we load the environment we use the .reset() method to reset the environment to the initial state. 
The lander starts at the top center of the environment and we can render the first frame of the environment by using 
the .render() method.
"""
env.reset()
PIL.Image.fromarray(env.render(mode='rgb_array'))

"""
In order to build our neural network later on we need to know the size of the state vector and the number of valid actions.
We can get this information from our environment by using the .observation_space.shape and action_space.n methods, respectively.
"""
state_size = env.observation_space.shape
num_actions = env.action_space.n

print('State Shape:', state_size)
print('Number of actions:', num_actions)






########################## 5 - Interacting with the Gym Environment ########################
"""
The Gym library implements the standard “agent-environment loop” formalism:

In the standard “agent-environment loop” formalism, an agent interacts with the environment 
in discrete time steps  t=0,1,2,.... At each time step  t, the agent uses a policy  𝜋 to select an action  A_t based 
on its observation of the environment's state  S_t. The agent receives a numerical reward  R_t 
and on the next time step, moves to a new state  S_(t+1).
"""
############### 5.1 Exploring the Environment's Dynamics ###############
"""
In Open AI's Gym environments, we use the .step() method to run a single time step of the environment's dynamics. 
In the version of gym that we are using the .step() method accepts an action and returns four values:

    observation (object): an environment-specific object representing your observation of the environment. 
    In the Lunar Lander environment this corresponds to a numpy array containing the positions and velocities 
    of the lander as described in section 3.2 Observation Space.

    reward (float): amount of reward returned as a result of taking the given action. 
    In the Lunar Lander environment this corresponds to a float of type numpy.float64 as described in section 3.3 Rewards.

    done (boolean): When done is True, it indicates the episode has terminated and it's time to reset the environment.

    info (dictionary): diagnostic information useful for debugging. We won't be using this variable in this notebook 
    but it is shown here for completeness.
"""

"""To begin an episode, we need to reset the environment to an initial state. We do this by using the .reset() method."""
# Reset the environment and get the initial state.
current_state = env.reset()

"""
Once the environment is reset, the agent can start taking actions in the environment by using the .step() method. 
Note that the agent can only take one action per time step.

In the cell below you can select different actions and see how the returned values change depending on the action taken. 
Remember that in this environment the agent has four discrete actions available and we specify them in code by using their corresponding numerical value:

    Do nothing = 0
    Fire right engine = 1
    Fire main engine = 2
    Fire left engine = 3
"""
# Select an action
action = 0

# Run a single time step of the environment's dynamics with the given action.
next_state, reward, done, _ = env.step(action)

# Display table with values.
utils2.display_table(current_state, action, next_state, reward, done)

# Replace the `current_state` with the state after the action is taken
current_state = next_state

"""In practice, when we train the agent we use a loop to allow the agent to take many consecutive actions during an episode."""







########################## 6 - Deep Q-Learning ########################
"""
In cases where both the state and action space are discrete we can estimate the action-value function iteratively by using the Bellman equation:
                                    𝑄𝑖+1(𝑠,𝑎)=𝑅 + 𝛾 * max 𝑄𝑖(𝑠′,𝑎′)

This iterative method converges to the optimal action-value function  𝑄∗(𝑠,𝑎) as  𝑖→∞. This means that the agent just needs to 
gradually explore the state-action space and keep updating the estimate of  𝑄(𝑠,𝑎) until it converges to the optimal 
action-value function  𝑄∗(𝑠,𝑎). However, in cases where the state space is continuous it becomes practically impossible 
to explore the entire state-action space. Consequently, this also makes it practically impossible to gradually estimate  𝑄(𝑠,𝑎)
until it converges to  𝑄∗(𝑠,𝑎).

In the Deep  𝑄-Learning, we solve this problem by using a neural network to estimate the action-value function  𝑄(𝑠,𝑎)≈𝑄∗(𝑠,𝑎). 
We call this neural network a  𝑄-Network and it can be trained by adjusting its weights at each iteration to minimize the mean-squared error in the Bellman equation.

Unfortunately, using neural networks in reinforcement learning to estimate action-value functions has proven to be highly unstable. 
Luckily, there's a couple of techniques that can be employed to avoid instabilities. 
These techniques consist of using a (i)Target Network and (ii)Experience Replay. We will explore these two techniques in the following sections.
"""

############### 6.1 Target Network ###############
"""
.......
the  𝑦 target is changing on every iteration. Having a constantly moving target can lead to oscillations and instabilities. 
To avoid this, we can create a separate neural network for generating the  𝑦 targets. We call this separate neural network,
the target  𝑄̂-Network and it will have the same architecture as the original  𝑄-Network.
.......
"""



#Exercise 1
"""
In this exercise you will create the  𝑄 and target 𝑄̂ networks and set the optimizer. Remember that the Deep  𝑄-Network (DQN) 
is a neural network that approximates the action-value function  𝑄(𝑠,𝑎)≈𝑄∗(𝑠,𝑎). It does this by learning how to map states to  𝑄 values.

To solve the Lunar Lander environment, we are going to employ a DQN with the following architecture:

    An Input layer that takes state_size as input.

    A Dense layer with 64 units and a relu activation function.

    A Dense layer with 64 units and a relu activation function.

    A Dense layer with num_actions units and a linear activation function. This will be the output layer of our network.

In the cell below you should create the  𝑄-Network and the target  𝑄̂-Network using the model architecture described above. 
Remember that both the  𝑄-Network and the target  𝑄̂ -Network have the same architecture.

Lastly, you should set Adam as the optimizer with a learning rate equal to ALPHA. Recall that ALPHA was defined 
in the Hyperparameters section.
"""

# UNQ_C1
# GRADED CELL

# Create the Q-Network
q_network = Sequential([
    ### START CODE HERE ### 
    tf.keras.layers.Input(shape=state_size),
    tf.keras.layers.Dense(64,activation='relu'),
    tf.keras.layers.Dense(64,activation='relu'),
    tf.keras.layers.Dense(num_actions,activation='linear')
    ### END CODE HERE ### 
    ])

# Create the target Q^-Network
target_q_network = Sequential([
    ### START CODE HERE ### 
    tf.keras.layers.Input(shape=state_size),
    tf.keras.layers.Dense(64,activation='relu'),
    tf.keras.layers.Dense(64,activation='relu'),
    tf.keras.layers.Dense(num_actions,activation='linear')
    ### END CODE HERE ###
    ])

### START CODE HERE ### 
optimizer = tf.keras.optimizers.Adam(learning_rate=ALPHA)
### END CODE HERE ###

q_network.summary()
target_q_network.summary()


# UNIT TEST
from public_tests import *

test_network(q_network)
test_network(target_q_network)
test_optimizer(optimizer, ALPHA) 




############### 6.2 Experience Replay ###############
"""
When an agent interacts with the environment, the states, actions, and rewards the agent experiences are sequential by nature. 
If the agent tries to learn from these consecutive experiences it can run into problems due to the strong correlations between them. 
To avoid this, we employ a technique known as Experience Replay to generate uncorrelated experiences for training our agent. 

Experience replay consists of storing the agent's experiences (i.e the states, actions, and rewards the agent receives) 
in a memory buffer and then sampling a random mini-batch of experiences from the buffer to do the learning. 
The experience tuples  (𝑆𝑡,𝐴𝑡,𝑅𝑡,𝑆𝑡+1) will be added to the memory buffer at each time step as the agent interacts with the environment.
"""

"""For convenience, we will store the experiences as named tuples."""
# Store experiences as named tuples
experience = namedtuple("Experience", field_names=["state", "action", "reward", "next_state", "done"])
"""
By using experience replay we avoid problematic correlations, oscillations and instabilities. 
In addition, experience replay also allows the agent to potentially use the same experience in multiple weight updates, 
which increases data efficiency.
"""








########################## 7 - Deep Q-Learning Algorithm with Experience Replay ########################
#Exercise 2
"""
In this exercise you will implement line 12 of the algorithm outlined in Fig 3 above and you will also compute the loss 
between the  𝑦 targets and the  𝑄(𝑠,𝑎) values. 
In the cell below, complete the compute_loss function by setting the  𝑦 targets equal to:

𝑦𝑗= 𝑅𝑗, if episode terminates at step 𝑗+1
 
    𝑅𝑗+𝛾max𝑎′𝑄̂ (𝑠𝑗+1,𝑎′)  , otherwise

Here are a couple of things to note:

The compute_loss function takes in a mini-batch of experience tuples. This mini-batch of experience tuples is unpacked 
to extract the states, actions, rewards, next_states, and done_vals. 
You should keep in mind that these variables are TensorFlow Tensors whose size will depend on the mini-batch size. 
For example, if the mini-batch size is 64 then both rewards and done_vals will be TensorFlow Tensors with 64 elements.

Using if/else statements to set the  𝑦 targets will not work when the variables are tensors with many elements. 
However, notice that you can use the done_vals to implement the above in a single line of code. 
To do this, recall that the done variable is a Boolean variable that takes the value True when an episode terminates 
at step  𝑗+1 and it is False otherwise. Taking into account that a Boolean value of True has the numerical value of 1 
and a Boolean value of False has the numerical value of 0, you can use the factor (1 - done_vals) to implement the above in a single line of code. 
Here's a hint: notice that (1 - done_vals) has a value of 0 when done_vals is True and a value of 1 when done_vals is False.
"""

# UNQ_C2
# GRADED FUNCTION: calculate_loss

def compute_loss(experiences, gamma, q_network, target_q_network):
    """ 
    Calculates the loss.
    
    Args:
      experiences: (tuple) tuple of ["state", "action", "reward", "next_state", "done"] namedtuples
      gamma: (float) The discount factor.
      q_network: (tf.keras.Sequential) Keras model for predicting the q_values
      target_q_network: (tf.keras.Sequential) Keras model for predicting the targets
          
    Returns:
      loss: (TensorFlow Tensor(shape=(0,), dtype=int32)) the Mean-Squared Error between
            the y targets and the Q(s,a) values.
    """

    # Unpack the mini-batch of experience tuples
    states, actions, rewards, next_states, done_vals = experiences
    
    # Compute max Q^(s,a)
    max_qsa = tf.reduce_max(target_q_network(next_states), axis=-1)
    
    # [Algorithm 1, Line 12] is implemented here
    # Set y = R if episode terminates, otherwise set y = R + γ max Q^(s,a).
    ### START CODE HERE ### 
    y_targets = done_vals*rewards + (1-done_vals)*(rewards+gamma*max_qsa)
    ### END CODE HERE ###
    
    # Get the q_values and reshape to match y_targets
    q_values = q_network(states)
    q_values = tf.gather_nd(q_values, tf.stack([tf.range(q_values.shape[0]),
                                                tf.cast(actions, tf.int32)], axis=1))
        
    # Compute the loss
    ### START CODE HERE ### 
    loss = MSE(y_targets,q_values) 
    ### END CODE HERE ### 
    
    return loss



# UNIT TEST    
test_compute_loss(compute_loss)



########################## 8 - Update the Network Weights ########################
"""
We will use the agent_learn function below to implement lines 12 -14 of the algorithm outlined in Fig 3. 
The agent_learn function will update the weights of the  𝑄 and target 𝑄̂ networks using a custom training loop. 
Because we are using a custom training loop we need to retrieve the gradients via a tf.GradientTape instance, 
and then call optimizer.apply_gradients() to update the weights of our  𝑄-Network. 

Note that we are also using the @tf.function decorator to increase performance. Without this decorator our training 
will take twice as long. If you would like to know more about how to increase performance with @tf.function take a look at the TensorFlow documentation.

The last line of this function updates the weights of the target  𝑄̂-Network using a soft update. If you want to know how this 
is implemented in code we encourage you to take a look at the utils2.update_target_network function in the utils2 module.
"""

@tf.function # decorator to increase performance
def agent_learn(experiences, gamma):
    """
    Updates the weights of the Q networks for a single time using a single gradinet descend step
    
    Args:
      experiences: (tuple) tuple of ["state", "action", "reward", "next_state", "done"] namedtuples
      gamma: (float) The discount factor.
    
    """
    
    # Calculate the loss
    with tf.GradientTape() as tape:
        loss = compute_loss(experiences, gamma, q_network, target_q_network)

    # Get the gradients of the loss with respect to the weights.
    gradients = tape.gradient(loss, q_network.trainable_variables)
    
    # Update the weights of the q_network.
    optimizer.apply_gradients(zip(gradients, q_network.trainable_variables)) # 

    # update the weights of target q_network using a soft update
    utils2.update_target_network(q_network, target_q_network)










########################## 9 - Train the Agent ########################
"""Here we will train the agent using the Deep Q-Learning algorithm with Experience Replay."""

start = time.time()

num_episodes = 2000
max_num_timesteps = 1000

total_point_history = []

num_p_av = 100    # number of total points to use for averaging
epsilon = 1.0     # initial ε value for ε-greedy policy (probability of choosing a random action). initially it is set to the maximum value of 1.0 to encourage exploration. we'll decrease this over time.

# [Algorithm 1, Line 1]: Create a memory buffer D with capacity N 
memory_buffer = deque(maxlen=MEMORY_SIZE)

# [Algorithm 1, Line 3]: Set the target network weights equal to the Q-Network weights
target_q_network.set_weights(q_network.get_weights())

# # [Algorithm 1, Line 4]
for i in range(num_episodes): 
    
    # [Algorithm 1, Line 5]: Reset the environment to the initial state and get the initial observation state So
    state = env.reset()
    total_points = 0
    
    # # [Algorithm 1, Line 6]
    for t in range(max_num_timesteps):
        
        # [Algorithm 1, Line 7]: From the current state S choose an action A using an ε-greedy policy
        state_qn = np.expand_dims(state, axis=0)  # state needs to be the right shape for the q_network. Neural networks, including Q-networks, often expect input data to be in batches, even if the batch size is 1. By expanding the dimensions of state, the code ensures that the input conforms to the expected shape of (batch_size, features), where batch_size is 1 in this case.
        q_values = q_network(state_qn)
        action = utils2.get_action(q_values, epsilon)
        
        # [Algorithm 1, Line 8]: Take action A and receive reward R and the next state S'
        next_state, reward, done, _ = env.step(action)
        
        # [Algorithm 1, Line 9]: Store experience tuple (S,A,R,S') in the memory buffer.
        # We store the done variable as well for convenience.
        memory_buffer.append(experience(state, action, reward, next_state, done))
        
        # [Algorithm 1, Line 10]: Only update the network every NUM_STEPS_FOR_UPDATE time steps.
        update = utils2.check_update_conditions(t, NUM_STEPS_FOR_UPDATE, memory_buffer)
        
        if update:
            # [Algorithm 1, Line 11]: Sample random mini-batch of experience tuples (S,A,R,S') from D
            experiences = utils2.get_experiences(memory_buffer)
            
            # [Algorithm 1, Line 12&13&14]: Set the y targets, perform a gradient descent step, and update the network weights.
            agent_learn(experiences, GAMMA)
        
        state = next_state.copy() # In this example, modifying state also changes next_state because both variables reference the same list object. Using .copy() avoids this issue.
        total_points += reward
         
        if done:
            break

    total_point_history.append(total_points)
    av_latest_points = np.mean(total_point_history[-num_p_av:]) # average of the latest num_p_av = 100 points
    
    # Update the ε value
    epsilon = utils2.get_new_eps(epsilon)

    print(f"\rEpisode {i+1} | Total point average of the last {num_p_av} episodes: {av_latest_points:.2f}", end="")

    if (i+1) % num_p_av == 0:
        print(f"\rEpisode {i+1} | Total point average of the last {num_p_av} episodes: {av_latest_points:.2f}")

    # We will consider that the environment is solved if we get an
    # average of 200 points in the last 100 episodes.
    if av_latest_points >= 200.0:
        print(f"\n\nEnvironment solved in {i+1} episodes!")
        q_network.save('lunar_lander_model.h5')
        break
        

tot_time = time.time() - start

print(f"\nTotal Runtime: {tot_time:.2f} s ({(tot_time/60):.2f} min)")




# Plot the total point history along with the moving average
utils.plot_history(total_point_history)







########################## 10 - See the Trained Agent In Action ########################
"""
Now that we have trained our agent, we can see it in action. We will use the utils.create_video function to create a video 
of our agent interacting with the environment using the trained  𝑄-Network. The utils.create_video function uses the imageio 
library to create the video. This library produces some warnings that can be distracting, so, to suppress these warnings we run the code below.
"""
# Suppress warnings from imageio
import logging
logging.getLogger().setLevel(logging.ERROR)



"""
In the cell below we create a video of our agent interacting with the Lunar Lander environment using the trained q_network. 
The video is saved to the videos folder with the given filename. We use the utils.embed_mp4 function to embed the video 
in the Jupyter Notebook so that we can see it here directly without having to download it.

We should note that since the lunar lander starts with a random "initial force" applied to its center of mass, 
every time you run the cell below you will see a different video. If the agent was trained properly, it should be able to 
land the lunar lander in the landing pad every time, regardless of the initial force applied to its center of mass.
"""

#filename = "./videos/lunar_lander.mp4"
filename = "C3_W3/videos/lunar_lander.mp4"

utils2.create_video(filename, env, q_network)
utils2.embed_mp4(filename)









################################################### 12 - References ###################################################
"""
If you would like to learn more about Deep Q-Learning, we recommend you check out the following papers.

Mnih, V., Kavukcuoglu, K., Silver, D. et al. Human-level control through deep reinforcement learning. Nature 518, 529–533 (2015).

Lillicrap, T. P., Hunt, J. J., Pritzel, A., et al. Continuous Control with Deep Reinforcement Learning. ICLR (2016).

Mnih, V., Kavukcuoglu, K., Silver, D. et al. Playing Atari with Deep Reinforcement Learning. arXiv e-prints. arXiv:1312.5602 (2013).
"""