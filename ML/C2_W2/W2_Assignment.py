import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.activations import linear, relu, sigmoid

import matplotlib.pyplot as plt
plt.style.use('./deeplearning.mplstyle')

import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)

from public_tests import * 

from autils import *
from lab_utils_softmax import plt_softmax
np.set_printoptions(precision=2)


############### ReLU Activation ##############
plt_act_trio()


############## Softmax Function ##############

###Exercise 1 : Let's create a NumPy implementation
# UNQ_C1
# GRADED CELL: my_softmax

def my_softmax(z):  
    """ Softmax converts a vector of values to a probability distribution.
    Args:
      z (ndarray (N,))  : input data, N features
    Returns:
      a (ndarray (N,))  : softmax of z
    """    
    ### START CODE HERE ### 
    
    ez = np.exp(z)
    a = ez/np.sum(ez)
    
    ### END CODE HERE ### 
    return a

#test your function by comparing with tensorflow result
z = np.array([1., 2., 3., 4.])
a = my_softmax(z)
a_tf = tf.nn.softmax(z)
print(f"my_softmax(z):         {a}")
print(f"tensorflow softmax(z): {a_tf}")

# BEGIN UNIT TEST  
test_my_softmax(my_softmax)
# END UNIT TEST  

## Below, vary the values of the z inputs. Note in particular how the exponential in the numerator magnifies small differences in the values. Note as well that the output values sum to one.
plt.close("all")
plt_softmax(my_softmax)


#################### Neural Networks #####################

#Problem Statement
"""In this exercise, you will use a neural network to recognize ten handwritten digits, 0-9. 
This is a multiclass classification task where one of n choices is selected. 
Automated handwritten digit recognition is widely used today - from recognizing zip codes (postal codes) on mail envelopes to recognizing amounts written on bank checks."""


#Dataset
"""You will start by loading the dataset for this task.

The load_data() function shown below loads the data into variables X and y
The data set contains 5000 training examples of handwritten digits.

Each training example is a 20-pixel x 20-pixel grayscale image of the digit.
Each pixel is represented by a floating-point number indicating the grayscale intensity at that location.
The 20 by 20 grid of pixels is “unrolled” into a 400-dimensional vector.
Each training examples becomes a single row in our data matrix X.
This gives us a 5000 x 400 matrix X where every row is a training example of a handwritten digit image.

The second part of the training set is a 5000 x 1 dimensional vector y that contains labels for the training set
y = 0 if the image is of the digit 0, y = 4 if the image is of the digit 4 and so on.
"""

# load dataset
X, y = load_data()

# View the variables and their dimensions
print ('The first element of X is: ', X[0])
print ('The first element of y is: ', y[0,0])
print ('The last element of y is: ', y[-1,0])

print ('The shape of X is: ' + str(X.shape))
print ('The shape of y is: ' + str(y.shape))



#Visualizing the Data
"""
You will begin by visualizing a subset of the training set.

In the cell below, the code randomly selects 64 rows from X, maps each row back to a 20 pixel by 20 pixel grayscale image and displays the images together.
The label for each image is displayed above the image
"""
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)
# You do not need to modify anything in this cell

m, n = X.shape

fig, axes = plt.subplots(8,8, figsize=(5,5))
fig.tight_layout(pad=0.13,rect=[0, 0.03, 1, 0.91]) #[left, bottom, right, top]

#fig.tight_layout(pad=0.5)
widgvis(fig)
for i,ax in enumerate(axes.flat):
    # Select random indices
    random_index = np.random.randint(m)
    
    # Select rows corresponding to the random indices and
    # reshape the image
    X_random_reshaped = X[random_index].reshape((20,20)).T
    
    # Display the image
    ax.imshow(X_random_reshaped, cmap='gray')
    
    # Display the label above the image
    ax.set_title(y[random_index,0])
    ax.set_axis_off()
    fig.suptitle("Label, image", fontsize=14)
plt.show()
    
    
#Model representation
"""
The neural network you will use in this assignment is shown in the figure below.
This has two dense layers with ReLU activations followed by an output layer with a linear activation.
"""

### Exercise 2: using Keras Sequential model and Dense Layer with a ReLU activation to construct the three layer network described above.
# UNQ_C2
# GRADED CELL: Sequential model
tf.random.set_seed(1234) # for consistent results
model = Sequential(
    [               
        ### START CODE HERE ### 
        tf.keras.Input(shape = (400,)), ##specify input shape (optional)
        Dense(units = 25, activation = 'relu', name = 'L1'),
        Dense(units = 15, activation = 'relu', name = 'L2'),
        Dense(units = 10, activation = 'linear', name = 'L3')
        
        ### END CODE HERE ### 
    ], name = "my_model" 
)

model.summary()
  
     

# Let's further examine the weights to verify that tensorflow produced the same dimensions as we calculated above.
[layer1, layer2, layer3] = model.layers
#### Examine Weights shapes
W1,b1 = layer1.get_weights()
W2,b2 = layer2.get_weights()
W3,b3 = layer3.get_weights()
print(f"W1 shape = {W1.shape}, b1 shape = {b1.shape}")
print(f"W2 shape = {W2.shape}, b2 shape = {b2.shape}")
print(f"W3 shape = {W3.shape}, b3 shape = {b3.shape}")


### Define loss function and omtimizer(if you wish), Train your model using model.fit()
model.compile(
    loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True), #defines a loss function namely SparseCategoricalCrossentropy and indicates the softmax should be included with the loss calculation by adding from_logits=True)
    optimizer=tf.keras.optimizers.Adam(learning_rate=0.001), # defines an optimizer. A popular choice is Adaptive Moment (Adam)
)

history = model.fit(
    X,y,
    epochs=40
)

plot_loss_tf(history)


## Prediction : To make a prediction, use Keras predict. Below, X[1015] contains an image of a two.

# Method 1: If the problem only requires a selection and probability is nor required. Just use NumPy argmax() on the model's output 
image_of_two = X[1015]
display_digit(image_of_two)

prediction = model.predict(image_of_two.reshape(1,400))  # prediction

print(f" predicting a Two: \n{prediction}")
print(f" Largest Prediction index: {np.argmax(prediction)}")

# Method 2: If the problem requires a probability, a softmax conversion is required
prediction_p = tf.nn.softmax(prediction) # return probability vector

print(f" predicting a Two. Probability vector: \n{prediction_p}")
print(f"Total of predictions: {np.sum(prediction_p):0.3f}")

y_hat = np.argmax(prediction_p)
print(f"np.argmax(prediction_p): {y_hat}")




###Let's compare the predictions vs the labels for a random sample of 64 digits
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)
# You do not need to modify anything in this cell

m, n = X.shape

fig, axes = plt.subplots(8,8, figsize=(5,5))
fig.tight_layout(pad=0.13,rect=[0, 0.03, 1, 0.91]) #[left, bottom, right, top]
widgvis(fig)
for i,ax in enumerate(axes.flat):
    # Select random indices
    random_index = np.random.randint(m)
    
    # Select rows corresponding to the random indices and
    # reshape the image
    X_random_reshaped = X[random_index].reshape((20,20)).T
    
    # Display the image
    ax.imshow(X_random_reshaped, cmap='gray')
    
    # Predict using the Neural Network
    prediction = model.predict(X[random_index].reshape(1,400))
    prediction_p = tf.nn.softmax(prediction)
    yhat = np.argmax(prediction_p)
    
    # Display the label above the image
    ax.set_title(f"{y[random_index,0]},{yhat}",fontsize=10)
    ax.set_axis_off()
fig.suptitle("Label, yhat", fontsize=14)
plt.show()


#Let's look at some of the errors.
print( f"{display_errors(model,X,y)} errors out of {len(X)} images")

"""
Note: increasing the number of training epochs can eliminate the errors on this data set.
"""