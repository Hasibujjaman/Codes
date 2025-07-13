import numpy as np
import math
import matplotlib.pyplot as plt
from lab_utils_multi import zscore_normalize_features, run_gradient_descent_feng
np.set_printoptions(precision=2)  # reduced display precision on numpy arrays

# create target data
x = np.arange(0, 20, 1)
y = 1 + x**2
X = x.reshape(-1, 1) ##The -1 argument tells the routine to compute the number of rows given the size of the array and the number of columns 
model_w,model_b = run_gradient_descent_feng(X,y,iterations=1000, alpha = 1e-2)
print(f"X = \n{X}\nX.shape = {X.shape}")
print(f"model_w = {model_w}, model_w.shape = {model_w.shape}")
print(f"model_b = {model_b}, model_w.shape = {model_b.shape}\n")

plt.scatter(x, y, marker='x', c='r', label="Actual Value"); plt.title("no feature engineering")
plt.plot(x,X@model_w + model_b, label="Predicted Value");  plt.xlabel("X"); plt.ylabel("y"); 
plt.legend(); plt.show()

print("\n\n")

""" Now let's try to fit a polynomial using linearization technique """

# create target data
x = np.arange(0, 20, 1)
y = 1 + x**2

# Engineer features 
X = x**2      #<-- added engineered feature
X = X.reshape(-1, 1)  #X should be a 2-D Matrix
model_w,model_b = run_gradient_descent_feng(X, y, iterations=10000, alpha = 1e-5)

plt.scatter(x, y, marker='x', c='r', label="Actual Value"); plt.title("Added x**2 feature")
plt.plot(x, np.dot(X,model_w) + model_b, label="Predicted Value"); plt.xlabel("x"); plt.ylabel("y"); 
plt.legend(); plt.show()
print(f"X.shape = {X.shape}, model_w.shape = {model_w.shape}, model_b.shape = {model_b.shape} , (dot(X.model_w)+model_b).shape = {(np.dot(X,model_w) + model_b).shape}\n")

print("\n\n")

#Selecting Features
"""
Above, we knew that an  x^2 term was required.
It may not always be obvious which features are required.
One could add a variety of potential features to try and find the most useful.
For example, what if we had instead tried y: w0*x0 + w1*x1^2 + w2*x2^3 + b ?
"""
# create target data
x = np.arange(0, 20, 1)
y = x**2

# engineer features .
X = np.c_[x, x**2, x**3]   #<-- added engineered feature
print(f"X = \n{X}\nX.shape = {X.shape}")
model_w,model_b = run_gradient_descent_feng(X, y, iterations=10000, alpha=1e-7)

plt.scatter(x, y, marker='x', c='r', label="Actual Value"); plt.title("x, x**2, x**3 features")
plt.plot(x, np.dot(X,model_w) + model_b, label="Predicted Value"); 
plt.xlabel("x"); plt.ylabel("y"); 
plt.legend(); plt.show()

"""
When selecting the appropriate features for the data:
---> less weight value implies less important/correct feature, and in extreme, 
     when the weight becomes zero or very close to zero, the associated feature is not useful in fitting the model to the data.
---> above, after fitting, the weight associated with the x^2 feature namely w1 is much larger than the weights for x(w0) or x3(w2)
     as it is the most useful in fitting the data.
"""

#An Alternate View
"""
Above, polynomial features were chosen based on how well they matched the target data. 
Another way to think about this is to note that we are still using linear regression once we have created new features. 
Given that, the best features will be linear relative to the target. This is best understood with an example.
"""
# create target data
x = np.arange(0, 20, 1)
y = x**2

# engineer features .
X = np.c_[x, x**2, x**3]   #<-- added engineered feature
X_features = ['x','x^2','x^3']
fig,ax=plt.subplots(1, 3, figsize=(12, 3), sharey=True)
for i in range(len(ax)):
    ax[i].scatter(X[:,i],y)
    ax[i].set_xlabel(X_features[i])
ax[0].set_ylabel("y")
plt.show()



#
#Scaling features
#
"""
If the data set has features with significantly different scales, one should apply feature scaling to speed gradient descent. 
In the example above, there is  x,  x^2 and  x^3 which will naturally have very different scales. 
Let's apply Z-score normalization to our example
"""
# create target data
x = np.arange(0,20,1)
X = np.c_[x, x**2, x**3]
print(f"Peak to Peak range by column in Raw        X:{np.ptp(X,axis=0)}")
print(f"X.shape = {X.shape}\n")

# add mean_normalization 
X = zscore_normalize_features(X)     
print(f"Peak to Peak range by column in Normalized X:{np.ptp(X,axis=0)}")

"""
Now we can try again with a more aggressive value of alpha:
"""
x = np.arange(0,20,1)
y = x**2

X = np.c_[x, x**2, x**3]
X = zscore_normalize_features(X) 

model_w, model_b = run_gradient_descent_feng(X, y, iterations=100000, alpha=1e-1)

plt.scatter(x, y, marker='x', c='r', label="Actual Value"); plt.title("Normalized x x**2, x**3 feature")
plt.plot(x,X@model_w + model_b, label="Predicted Value"); plt.xlabel("x"); plt.ylabel("y"); 
plt.legend(); plt.show()

#
# With feature engineering, even quite complex functions can be modeled
#
x = np.arange(0,20,1)
y = np.cos(x/2)

X = np.c_[x, x**2, x**3,x**4, x**5, x**6, x**7, x**8, x**9, x**10, x**11, x**12, x**13]
print(f"X=\n{X}\n\n")
X = zscore_normalize_features(X) 

print(f"X_Normalized=\n{X}\n")

model_w,model_b = run_gradient_descent_feng(X, y, iterations=1000000, alpha = 1e-1)

plt.scatter(x, y, marker='x', c='r', label="Actual Value"); plt.title("Normalized x x**2, x**3,....,x**13 feature")
plt.plot(x,X@model_w + model_b, label="Predicted Value"); plt.xlabel("x"); plt.ylabel("y"); 
plt.legend(); plt.show()
