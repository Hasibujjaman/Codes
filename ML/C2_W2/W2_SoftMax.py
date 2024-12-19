import numpy as np
import matplotlib.pyplot as plt
plt.style.use('./deeplearning.mplstyle')
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from IPython.display import display, Markdown, Latex
from sklearn.datasets import make_blobs

from matplotlib.widgets import Slider
from lab_utils_common import dlc
from lab_utils_softmax import plt_softmax
import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)

##### Softmax Function #######
def my_softmax(z):
    ez = np.exp(z)              #element-wise exponenial
    sm = ez/np.sum(ez)
    return(sm)

plt.close("all")
plt_softmax(my_softmax)



"""
This lab will discuss two ways of implementing the softmax, cross-entropy loss in Tensorflow, the 'obvious' method and the 'preferred' method. 
The former is the most straightforward while the latter is more numerically stable.
"""
##Let's start by creating a dataset to train a multiclass classification model.

# make  dataset for example
centers = [[-5, 2], [-2, -2], [1, 2], [5, -2]]
X_train, y_train = make_blobs(n_samples=2000, centers=centers, cluster_std=1.0,random_state=30)

######### The obvious/Non-preferred method ##########
"""
The model below is implemented with the softmax as an activation in the final Dense layer. The loss function is separately specified in the compile directive.

The loss function is SparseCategoricalCrossentropy. This loss is described in (3) above. In this model, the softmax takes place in the last layer. 
The loss function takes in the softmax output which is a vector of probabilities.
"""
model = Sequential(
    [ 
        Dense(25, activation = 'relu'),
        Dense(15, activation = 'relu'),
        Dense(4, activation = 'softmax')    # < softmax activation here
    ]
)
model.compile(
    loss=tf.keras.losses.SparseCategoricalCrossentropy(),
    optimizer=tf.keras.optimizers.Adam(0.001),
)

model.fit(
    X_train,y_train,
    epochs=10
)

#Because the softmax is integrated into the output layer, the output is a vector of probabilities. Verify that here
p_nonpreferred = model.predict(X_train)
print(p_nonpreferred [:2])
print("largest value", np.max(p_nonpreferred), "smallest value", np.min(p_nonpreferred))



############ Preferred Method ############
"""
Recall from lecture, more stable and accurate results can be obtained if the softmax and loss are combined during training.
In the preferred organization the final layer has a linear activation. For historical reasons, the outputs in this form are referred to as logits.
The loss function has an additional argument: from_logits = True
This informs the loss function that the softmax operation should be included in the loss calculation.
"""
preferred_model = Sequential(
    [ 
        Dense(25, activation = 'relu'),
        Dense(15, activation = 'relu'),
        Dense(4, activation = 'linear')   #<-- Note
    ]
)
preferred_model.compile(
    loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),  #<-- Note
    optimizer=tf.keras.optimizers.Adam(0.001),
)

preferred_model.fit(
    X_train,y_train,
    epochs=10
)



###Output Handling
"""
Notice that in the preferred model, the outputs are not probabilities, but can range from large negative numbers to large positive numbers.
The output must be sent through a softmax when performing a prediction that expects a probability. Let's look at the preferred model outputs:
"""
p_preferred = preferred_model.predict(X_train)
print(f"two example output vectors:\n {p_preferred[:2]}")
print("largest value", np.max(p_preferred), "smallest value", np.min(p_preferred))

"""The output predictions are not probabilities! If the desired output are probabilities, the output should be be processed by a softmax."""
sm_preferred = tf.nn.softmax(p_preferred).numpy()
print(f"two example output vectors:\n {sm_preferred[:2]}")
print("largest value", np.max(sm_preferred), "smallest value", np.min(sm_preferred))

"""To select the most likely category, the softmax is not required. One can find the index of the largest output using np.argmax()."""
for i in range(5):
    print( f"{p_preferred[i]}, category: {np.argmax(p_preferred[i])}")
    
    
    
    
############     SparseCategorialCrossentropy or CategoricalCrossEntropy     ###############
"""
Tensorflow has two potential formats for target values and the selection of the loss defines which is expected.

SparseCategorialCrossentropy: expects the target to be an integer corresponding to the index. For example, if there are 10 potential target values, y would be between 0 and 9.
CategoricalCrossEntropy: Expects the target value of an example to be one-hot encoded where the value at the target index is 1 while the other N-1 entries are zero. An example with 10 potential target values, where the target is 2 would be [0,0,1,0,0,0,0,0,0,0].
"""

## Complex model

# UNQ_C3
# GRADED CELL: model
import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)

tf.random.set_seed(1234)
model = Sequential(
    [
        ### START CODE HERE ### 
        Dense(120, activation = 'relu'),
        Dense(40, activation = 'relu'),
        Dense(6, activation = 'linear')
        
        ### END CODE HERE ### 

    ], name="Complex"
)
model.compile(
    ### START CODE HERE ### 
    loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits = True),
    optimizer=tf.keras.optimizers.Adam(0.01),
    ### END CODE HERE ### 
)

model.fit(
    X_train, y_train,
    epochs=1000
)

# BEGIN UNIT TEST
model.summary()

model_test(model, classes, X_train.shape[1]) 
# END UNIT TEST



#make a model for plotting routines to call
model_predict = lambda Xl: np.argmax(tf.nn.softmax(model.predict(Xl)).numpy(),axis=1)
plt_nn(model_predict,X_train,y_train, classes, X_cv, y_cv, suptitle="Complex Model")


training_cerr_complex = eval_cat_err(y_train, model_predict(X_train))
cv_cerr_complex = eval_cat_err(y_cv, model_predict(X_cv))
print(f"categorization error, training, complex model: {training_cerr_complex:0.3f}")
print(f"categorization error, cv,       complex model: {cv_cerr_complex:0.3f}")




##  Simple model
"""
Below, compose a two-layer model:

Dense layer with 6 units, relu activation
Dense layer with 6 units and a linear activation. Compile using
loss with SparseCategoricalCrossentropy, remember to use from_logits=True
Adam optimizer with learning rate of 0.01.
"""

# UNQ_C4
# GRADED CELL: model_s

tf.random.set_seed(1234)
model_s = Sequential(
    [
        ### START CODE HERE ### 
        Dense(6,activation='relu'),
        Dense(6,activation='linear')
        
        ### END CODE HERE ### 
    ], name = "Simple"
)
model_s.compile(
    ### START CODE HERE ### 
    loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits = True),
    optimizer=tf.keras.optimizers.Adam(0.01),
    ### START CODE HERE ### 
)


import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)

model_s.fit(
    X_train,y_train,
    epochs=1000
)


# BEGIN UNIT TEST
model_s.summary()

model_s_test(model_s, classes, X_train.shape[1])
# END UNIT TEST



#make a model for plotting routines to call
model_predict_s = lambda Xl: np.argmax(tf.nn.softmax(model_s.predict(Xl)).numpy(),axis=1)
plt_nn(model_predict_s,X_train,y_train, classes, X_cv, y_cv, suptitle="Simple Model")


training_cerr_simple = eval_cat_err(y_train, model_predict_s(X_train))
cv_cerr_simple = eval_cat_err(y_cv, model_predict_s(X_cv))
print(f"categorization error, training, simple model, {training_cerr_simple:0.3f}, complex model: {training_cerr_complex:0.3f}" )
print(f"categorization error, cv,       simple model, {cv_cerr_simple:0.3f}, complex model: {cv_cerr_complex:0.3f}" )

"""Our simple model has a little higher classification error on training data but does better on cross-validation data than the more complex model."""


############## 5. Regularization ¶ ##############

"""As in the case of polynomial regression, one can apply regularization to moderate the impact of a more complex model. Let's try this below."""
"""
Reconstruct your complex model, but this time include regularization. Below, compose a three-layer model:

Dense layer with 120 units, relu activation, kernel_regularizer=tf.keras.regularizers.l2(0.1)
Dense layer with 40 units, relu activation, kernel_regularizer=tf.keras.regularizers.l2(0.1)
Dense layer with 6 units and a linear activation. 

Compile using
loss with SparseCategoricalCrossentropy, remember to use from_logits=True
Adam optimizer with learning rate of 0.01.
"""

