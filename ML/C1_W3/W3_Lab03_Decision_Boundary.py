import numpy as np
import matplotlib.pyplot as plt
from lab_utils_common import plot_data, sigmoid, draw_vthresh
plt.style.use('./deeplearning.mplstyle')

#Dataset
X = np.array([[0.5, 1.5], [1,1], [1.5, 0.5], [3, 0.5], [2, 2], [1, 2.5]])
print(f"\nX.shape = {X.shape}")
y = np.array([0, 0, 0, 1, 1, 1])
print(f"(Before reshaping) y.shape = {y.shape}")
y = y.reshape(-1,1)
print(f"(After reshaping) y.shape = {y.shape}")

#Plot data
fig,ax = plt.subplots(1,1,figsize=(4,4))
plot_data(X, y, ax)

ax.axis([0, 4, 0, 3.5])
ax.set_ylabel('$x_1$')
ax.set_xlabel('$x_0$')
plt.show()

#
#Plotting decision boundary
#
"""
Let's say that you trained the model and get the parameters as  w0 = 1, w1 = 1, b = -3,
i.e, the decision boundary is given by, z = x0 + x1 - 3 = 0 
You'll learn how to fit these parameters(w0,w1,b) to the data via gradient descend later
"""
#Now we need points to plot the decision boundary
# Choose values between 0 and 6
x0 = np.arange(0,6)
x1 = 3 - x0
fig,ax = plt.subplots(1,1,figsize=(5,4))
# Plot the decision boundary
ax.plot(x0,x1, c="b")
ax.axis([0, 4, 0, 3.5])

# Fill the region below the line
ax.fill_between(x0,x1, alpha=0.2)

# Plot the original data
plot_data(X,y,ax)
ax.set_ylabel(r'$x_1$')
ax.set_xlabel(r'$x_0$')
plt.show()

"""
By using higher order polynomial terms (eg, z = x0^2 + x1 - 1),
we can come up with more complex non-linear boundaries
"""