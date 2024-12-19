import numpy as np
import matplotlib.pyplot as plt
from utils2 import *


########################## 2 - Anomaly detection ##########################

############## 2.1 Problem Statement ##############
"""
In this exercise, you will implement an anomaly detection algorithm to detect anomalous behavior in server computers.

The dataset contains two features -

throughput (mb/s) and
latency (ms) of response of each server.


While your servers were operating, you collected  𝑚=307 examples of how they were behaving, 
and thus have an unlabeled dataset  {x(1),…,x(𝑚)}.

    You suspect that the vast majority of these examples are “normal” (non-anomalous) examples of the servers operating normally, but there might also be some examples of servers acting anomalously within this dataset.


You will use a Gaussian model to detect anomalous examples in your dataset.

    You will first start on a 2D dataset that will allow you to visualize what the algorithm is doing.

    On that dataset you will fit a Gaussian distribution and then find values that have very low probability and hence can be considered anomalies.

    After that, you will apply the anomaly detection algorithm to a larger dataset with many dimensions.


"""


############## 2.2 Dataset ##############
"""
You will start by loading the dataset for this task.

The load_data() function shown below loads the data into the variables X_train, X_val and y_val
    You will use X_train to fit a Gaussian distribution
    You will use X_val and y_val as a cross validation set to select a threshold and determine anomalous vs normal examples
"""
# Load the dataset
X_train, X_val, y_val = load_data()

# Display the first five elements of X_train
print("The first 5 elements of X_train are:\n", X_train[:5])  

# Display the first five elements of X_val
print("The first 5 elements of X_val are\n", X_val[:5])  

# Display the first five elements of y_val
print("The first 5 elements of y_val are\n", y_val[:5])  


## Check the dimensions of your variables
print ('The shape of X_train is:', X_train.shape)
print ('The shape of X_val is:', X_val.shape)
print ('The shape of y_val is: ', y_val.shape)




## Visualize your data
"""
Before starting on any task, it is often useful to understand the data by visualizing it.

    For this dataset, you can use a scatter plot to visualize the data (X_train), since it has only two properties to plot (throughput and latency)
"""
# Create a scatter plot of the data. To change the markers to blue "x",
# we used the 'marker' and 'c' parameters
plt.scatter(X_train[:, 0], X_train[:, 1], marker='x', c='b') 

# Set the title
plt.title("The first dataset")
# Set the y-axis label
plt.ylabel('Throughput (mb/s)')
# Set the x-axis label
plt.xlabel('Latency (ms)')
# Set axis range
plt.axis([0, 30, 0, 30])
plt.show()



############## 2.3 Gaussian distribution ##############
# UNQ_C1
# GRADED FUNCTION: estimate_gaussian

def estimate_gaussian(X): 
    """
    Calculates mean and variance of all features 
    in the dataset
    
    Args:
        X (ndarray): (m, n) Data matrix
    
    Returns:
        mu (ndarray): (n,) Mean of all features
        var (ndarray): (n,) Variance of all features
    """

    m, n = X.shape
    
    ### START CODE HERE ### 
    mu = np.sum(X, axis=0)/m
    var = np.sum((X-mu)**2, axis=0)/m
    
    
    ### END CODE HERE ### 
        
    return mu, var



# Estimate mean and variance of each feature
mu, var = estimate_gaussian(X_train)              

print("\nMean of each feature:", mu)
print("Variance of each feature:", var)
print("\nvar.dim:", var.ndim), print("var.shape:", var.shape,"\n")
    
# UNIT TEST
from public_tests2 import *
estimate_gaussian_test(estimate_gaussian)






# Returns the density of the multivariate normal
# at each data point (row) of X_train
p = multivariate_gaussian(X_train, mu, var)

#Plotting code 
visualize_fit(X_train, mu, var)





############## 2.4 Selecting the threshold 𝜖 ##############
"""
Now that you have estimated the Gaussian parameters, you can investigate which examples have a very high probability 
given this distribution and which examples have a very low probability.

    The low probability examples are more likely to be the anomalies in our dataset.

    One way to determine which examples are anomalies is to select a threshold based on a cross validation set.



In this section, you will complete the code in select_threshold to select the threshold  𝜀 using the  F1 score
on a cross validation set.

    For this, we will use a cross validation set  {(x(1)cv,y(1)cv),…,(x(𝑚cv)cv,y(𝑚cv)cv)}, where the label  y=1 corresponds 
    to an anomalous example, and  y=0 corresponds to a normal example.

    For each cross validation example, we will compute  p(x(i)cv). The vector of all of these probabilities  p(x(1)cv),…,p(x(𝑚cv)cv) is 
    passed to select_threshold in the vector p_val.

The corresponding labels  y(1)cv,…,y(𝑚cv)cv are passed to the same function in the vector y_val.
"""


# UNQ_C2
# GRADED FUNCTION: select_threshold

def select_threshold(y_val, p_val): 
    """
    Finds the best threshold to use for selecting outliers 
    based on the results from a validation set (p_val) 
    and the ground truth (y_val)
    
    Args:
        y_val (ndarray): Ground truth on validation set
        p_val (ndarray): Results on validation set
        
    Returns:
        epsilon (float): Threshold chosen 
        F1 (float):      F1 score by choosing epsilon as threshold
    """ 

    best_epsilon = 0
    best_F1 = 0
    F1 = 0
    
    step_size = (max(p_val) - min(p_val)) / 1000
    
    for epsilon in np.arange(min(p_val), max(p_val), step_size):
    
        ### START CODE HERE ### 
        predictions = p_val < epsilon
        
        tp = np.sum((predictions ==1) & (y_val == 1))
        fp = np.sum((predictions == 1) & (y_val == 0))
        fn = np.sum((predictions == 0) & (y_val == 1))
        
        prec = tp/(tp+fp)
        rec = tp/(tp+fn)
        
        F1 = 2*prec*rec*1/(prec+rec)
        
        
        ### END CODE HERE ### 
        
        if F1 > best_F1:
            best_F1 = F1
            best_epsilon = epsilon
        
    return best_epsilon, best_F1


p_val = multivariate_gaussian(X_val, mu, var)
epsilon, F1 = select_threshold(y_val, p_val)

print('Best epsilon found using cross-validation: %e' % epsilon)
print('Best F1 on Cross Validation Set: %f' % F1)
    
# UNIT TEST
select_threshold_test(select_threshold)






# Find the outliers in the training set 
outliers = p < epsilon

# Visualize the fit
visualize_fit(X_train, mu, var)

# Draw a red circle around those outliers
plt.plot(X_train[outliers, 0], X_train[outliers, 1], 'ro', markersize= 10,markerfacecolor='none', markeredgewidth=2)
plt.show()




########################## 3 - High dimensional dataset ##########################
"""
Now, we will run the anomaly detection algorithm that you implemented on a more realistic and much harder dataset.

In this dataset, each example is described by 11 features, capturing many more properties of your compute servers.

Let's start by loading the dataset.

    The load_data() function shown below loads the data into variables X_train_high, X_val_high and y_val_high

        _high is meant to distinguish these variables from the ones used in the previous part

        We will use X_train_high to fit Gaussian distribution

        We will use X_val_high and y_val_high as a cross validation set to select a threshold and determine anomalous vs normal examples
"""

# load the dataset
X_train_high, X_val_high, y_val_high = load_data_multi()

# Check the dimensions of your variables
print ('The shape of X_train_high is:', X_train_high.shape)
print ('The shape of X_val_high is:', X_val_high.shape)
print ('The shape of y_val_high is: ', y_val_high.shape)




# Apply the same steps to the larger dataset

# Estimate the Gaussian parameters
mu_high, var_high = estimate_gaussian(X_train_high)

# Evaluate the probabilites for the training set
p_high = multivariate_gaussian(X_train_high, mu_high, var_high)

# Evaluate the probabilites for the cross validation set
p_val_high = multivariate_gaussian(X_val_high, mu_high, var_high)

# Find the best threshold
epsilon_high, F1_high = select_threshold(y_val_high, p_val_high)

print('Best epsilon found using cross-validation: %e'% epsilon_high)
print('Best F1 on Cross Validation Set:  %f'% F1_high)
print('# Anomalies found: %d'% sum(p_high < epsilon_high))


