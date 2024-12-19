"""
To fix a high bias problem, you can:

(i)try adding polynomial features
(ii)try getting additional features
(iii)try decreasing the regularization parameter

To fix a high variance problem, you can:

(i)try increasing the regularization parameter
(ii)try smaller sets of features
(iii)get more training examples
"""

"""
Establishing Baseline Level of Performance¶
Before you can diagnose a model for high bias or high variance, 
it is usually helpful to first have an idea of what level of error you can reasonably get to. 
As mentioned in class, you can use any of the following to set a baseline level of performance:

(i)human level performance
(ii)competing algorithm's performance
(iii)guess based on experience

Real-world data can be very noisy and it's often infeasible to get to 0% error.
For example, you might think that you have a high bias problem because you're getting 10% training and 
15% cross validation error on a computer vision application. However, you later found out that 
even humans can't perform better than 10% error. If you consider this the baseline level, 
then you now instead have a high variance problem because you've prioritized minimizing the gap between cross validation and training error.
"""

# for building linear regression models
from sklearn.linear_model import LinearRegression, Ridge

# import lab utility functions in utils.py
import utils 


############ Fixing High Bias : when the training error is far worse than the baseline level of performance ############
### (i) Try adding polynomial features


# Split the dataset into train, cv, and test
x_train, y_train, x_cv, y_cv, x_test, y_test = utils.prepare_dataset('C2_W3/data/c2w3_lab2_data1.csv')

print(f"the shape of the training set (input) is: {x_train.shape}")
print(f"the shape of the training set (target) is: {y_train.shape}\n")
print(f"the shape of the cross validation set (input) is: {x_cv.shape}")
print(f"the shape of the cross validation set (target) is: {y_cv.shape}\n")

# Preview the first 5 rows
print(f"first 5 rows of the training inputs (1 feature):\n {x_train[:5]}\n")

# Instantiate the regression model class
model = LinearRegression()

# Train and plot polynomial regression models
utils.train_plot_poly(model, x_train, y_train, x_cv, y_cv, max_degree=10, baseline=400)

"""if the baseline is defined lower (e.g. you consulted an expert regarding the acceptable error), 
then the models are still considered high bias. You can then try other methods to improve this."""
# Train and plot polynomial regression models. Bias is defined lower.
utils.train_plot_poly(model, x_train, y_train, x_cv, y_cv, max_degree=10, baseline=250)


### (ii) Try getting additional features
"""Your dataset will now have 2 columns for the input features as shown below"""

x_train, y_train, x_cv, y_cv, x_test, y_test = utils.prepare_dataset('C2_W3/data/c2w3_lab2_data2.csv')

print(f"the shape of the training set (input) is: {x_train.shape}")
print(f"the shape of the training set (target) is: {y_train.shape}\n")
print(f"the shape of the cross validation set (input) is: {x_cv.shape}")
print(f"the shape of the cross validation set (target) is: {y_cv.shape}\n")

# Preview the first 5 rows
print(f"first 5 rows of the training inputs (2 features):\n {x_train[:5]}\n")


# Instantiate the model class
model = LinearRegression()

# Train and plot polynomial regression models. Dataset used has two features.
utils.train_plot_poly(model, x_train, y_train, x_cv, y_cv, max_degree=6, baseline=250)





### (iii) Try decreasing the regularization parameter
"""Ridge regression is used to regularize the model.
The cell below trains a 4th degree polynomial model using the Ridge class which allows you 
to set a regularization parameter (i.e. lambda or  𝜆). You will try several values and compare the results."""
# Define lambdas to plot
reg_params = [10, 5, 2, 1, 0.5, 0.2, 0.1]

# Define degree of polynomial and train for each value of lambda
utils.train_plot_reg_params(reg_params, x_train, y_train, x_cv, y_cv, degree= 4, baseline=250)




############ Fixing High Variance : when the training error is close to the baseline level of performance but cross validation error is still high ############
### (i) Try increasing the regularization parameter
# Define lambdas to plot
reg_params = [0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1]

# Define degree of polynomial and train for each value of lambda
utils.train_plot_reg_params(reg_params, x_train, y_train, x_cv, y_cv, degree= 4, baseline=250)



### (ii) Try smaller sets of features

# Prepare dataset with randomID feature
x_train, y_train, x_cv, y_cv, x_test, y_test = utils.prepare_dataset('C2_W3/data/c2w3_lab2_data2.csv')

# Preview the first 5 rows
print(f"first 5 rows of the training set with 2 features:\n {x_train[:5]}\n")

# Prepare dataset with randomID feature
x_train, y_train, x_cv, y_cv, x_test, y_test = utils.prepare_dataset('C2_W3/data/c2w3_lab2_data3.csv')

# Preview the first 5 rows
print(f"first 5 rows of the training set with 3 features (1st column is a random ID):\n {x_train[:5]}\n")

# Define the model
model = LinearRegression()

# Define properties of the 2 datasets
file1 = {'filename':'C2_W3/data/c2w3_lab2_data3.csv', 'label': '3 features', 'linestyle': 'dotted'}
file2 = {'filename':'C2_W3/data/c2w3_lab2_data2.csv', 'label': '2 features', 'linestyle': 'solid'}
files = [file1, file2]

# Train and plot for each dataset
utils.train_plot_diff_datasets(model, files, max_degree=4, baseline=250)




### (iii) Get more training examples
"""You can try to minimize the cross validation error by getting more examples"""
# Prepare the dataset
x_train, y_train, x_cv, y_cv, x_test, y_test = utils.prepare_dataset('C2_W3/data/c2w3_lab2_data4.csv')
print(f"the shape of the entire training set (input) is: {x_train.shape}")
print(f"the shape of the entire training set (target) is: {y_train.shape}\n")
print(f"the shape of the entire cross validation set (input) is: {x_cv.shape}")
print(f"the shape of the entire cross validation set (target) is: {y_cv.shape}\n")

# Instantiate the model class
model = LinearRegression()

# Define the degree of polynomial and train the model using subsets of the dataset.
utils.train_plot_learning_curve(model, x_train, y_train, x_cv, y_cv, degree= 4, baseline=250)


"""From the results, it shows that the cross validation error starts to approach the training error as you increase the dataset size. 
Another insight you can get from this is that adding more examples will not likely solve a high bias problem. 
That's because the training error remains relatively flat even as the dataset increases"""
