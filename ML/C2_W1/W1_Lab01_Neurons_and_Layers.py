import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras.layers import Dense, Input
from tensorflow.keras import Sequential
from tensorflow.keras.losses import MeanSquaredError, BinaryCrossentropy
from tensorflow.keras.activations import sigmoid
from lab_utils_common import dlc
from lab_neurons_utils import plt_prob_1d, sigmoidnp, plt_linear, plt_logistic
plt.style.use('./deeplearning.mplstyle')
import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)



X_train = np.array([[1.0], [2.0]], dtype=np.float32)           #(size in 1000 square feet)
Y_train = np.array([[300.0], [500.0]], dtype=np.float32)       #(price in 1000s of dollars)

fig, ax = plt.subplots(1,1)
ax.scatter(X_train, Y_train, marker='x', c='r', label="Data Points")
ax.legend( fontsize='xx-large')
ax.set_ylabel('Price (in 1000s of dollars)', fontsize='xx-large')
ax.set_xlabel('Size (1000 sqft)', fontsize='xx-large')
plt.show()

################################ """Regression/Linear Model using TensorFlow"""#########################
                            
#We can define a layer with one neuron or unit and compare it to the familiar linear regression function

linear_layer = tf.keras.layers.Dense(units=1, activation = 'linear', )
linear_layer.get_weights() #There are no weights as the weights are not yet instantiated. Let's try the model on one example in X_train. This will trigger the instantiation of the weights.
#Note, the input to the layer must be 2-D, so we'll reshape it.
a1 = linear_layer(X_train[0].reshape(1,1)) #linear_layer() returns the output(activatio(s))

print(a1) #The result is a tensor (another name for an array) with a shape of (1,1) or one entry

#Now let's look at the weights and bias. 
#These weights(wi) are randomly initialized to small numbers and the bias(b) defaults to being initialized to zero.
w, b= linear_layer.get_weights()
print(f"w = {w}, b={b}")

#The weights are initialized to random values so let's set them to some known values.
set_w = np.array([[200]])
set_b = np.array([100])
# set_weights takes a list of numpy arrays
linear_layer.set_weights([set_w, set_b])
print(linear_layer.get_weights())

#Let's compare the layer output to equation (1) : f(x) = w.x+b
a1 = linear_layer(X_train[0].reshape(1,1))
print(a1) 
a1_manually = np.dot(set_w,X_train[0].reshape(1,1)) + set_b
print(a1_manually) 
#They produce the same values! 
# Now, we can use our linear layer to make predictions on our training data using (i)tensorflow & (ii)numpy
prediction_tf = linear_layer(X_train)
prediction_np = np.dot( X_train, set_w) + set_b

plt_linear(X_train, Y_train, prediction_tf, prediction_np)


######################### Neuron with Sigmoid activation ###########################
X_train = np.array([0., 1, 2, 3, 4, 5], dtype=np.float32).reshape(-1,1)  # 2-D Matrix
Y_train = np.array([0,  0, 0, 1, 1, 1], dtype=np.float32).reshape(-1,1)  # 2-D Matrix


pos = Y_train == 1
neg = Y_train == 0

fig,ax = plt.subplots(1,1,figsize=(4,3))
ax.scatter(X_train[pos], Y_train[pos], marker='x', s=80, c = 'red', label="y=1")
ax.scatter(X_train[neg], Y_train[neg], marker='o', s=100, label="y=0", facecolors='none', 
              edgecolors=dlc["dlblue"],lw=3)

ax.set_ylim(-0.08,1.1)
ax.set_ylabel('y', fontsize=12)
ax.set_xlabel('x', fontsize=12)
ax.set_title('one variable plot')
ax.legend(fontsize=12)
plt.show()


#Logistic Neuron
"""We can implement a 'logistic neuron' by adding a sigmoid activation.
This section will create a Tensorflow Model that contains our logistic layer to demonstrate an alternate method of creating models. 
Tensorflow is most often used to create multi-layer models. 
The Sequential model is a convenient means of constructing these models."""

model = Sequential(
    [
        tf.keras.layers.Dense(1, input_dim=1,  activation = 'sigmoid', name='L1')
    ]
)
model.summary() # model.summary() shows the layers and number of parameters in the model


logistic_layer = model.get_layer('L1') #creates a logistic layer
w,b = logistic_layer.get_weights()
print(w,b)
print(w.shape,b.shape)

#Let's set the weight and bias to some known values.
set_w = np.array([[2]])
set_b = np.array([-4.5])
# set_weights takes a list of numpy arrays
logistic_layer.set_weights([set_w, set_b])
print(logistic_layer.get_weights())


#Let's compare the layer output and numpy output (logistic regression that we've studied in course 1)
a1 = model.predict(X_train[0].reshape(1,1))
print(a1)
alog = sigmoidnp(np.dot(set_w,X_train[0].reshape(1,1)) + set_b)
print(alog)
plt_logistic(X_train, Y_train, model, set_w, set_b, pos, neg)

