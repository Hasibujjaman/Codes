import numpy as np
from utils import *

# Do not modify
num_states = 6
num_actions = 2


terminal_left_reward = 100
terminal_right_reward = 40
each_step_reward = 0

# Discount factor
gamma = 0.5

# Probability of going in the wrong direction
misstep_prob = 0


generate_visualization(terminal_left_reward, terminal_right_reward, each_step_reward, gamma, misstep_prob)




# moddify the gamma value (discount factor) to see how it affects the state-action value function
gamma = 0.9
for i in range(8):
    generate_visualization(terminal_left_reward, terminal_right_reward, each_step_reward, gamma, misstep_prob)
    gamma -= 0.1