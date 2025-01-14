import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
from pca_utils import plot_widget
from bokeh.io import show, output_notebook
from bokeh.plotting import figure
import matplotlib.pyplot as plt
import plotly.offline as py

# py.init_notebook_mode()
# output_notebook()

# Load data (2D)
X = np.array([[ 99,  -1],
       [ 98,  -1],
       [ 97,  -2],
       [101,   1],
       [102,   1],
       [103,   2]])

# Plot the original data
print("\nOriginal X:\n",X)
plt.plot(X[:,0], X[:,1], 'ro')
plt.title('Original Data')
plt.show()

###################### PCA : 2D to 2D ######################
# Loading the PCA algorithm
pca_2 = PCA(n_components=2)
print("\n################# PCA: 2D to 2D ###################\n",pca_2)

# Let's fit the data. We do not need to scale it, since sklearn's implementation already handles it.
pca_2.fit(X)

# Examine how much variance is explained by the principal components
print("\nExplained variance ratio:\n",pca_2.explained_variance_ratio_)
"""
The coordinates on the first principal component (first axis) are enough to retain 99.24% of the information ("explained variance"). 
The second principal component adds an additional 0.76% of the information ("explained variance") that is not stored 
in the first principal component coordinates.
"""

# Transform the data
X_trans_2 = pca_2.transform(X)


# Inverse transform the data if needed
X_reduced_2 = pca_2.inverse_transform(X_trans_2)

# Plot the inverse transformed data to check if how much it matches the original data
print("\nInverse transformed X:\n", X_reduced_2)
plt.plot(X_reduced_2[:, 0], X_reduced_2[:, 1], 'bx')
plt.title('Inverse Transformed Data (PCA 2D to 2D)')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.show()

###################### PCA : 2D to 1D ######################
pca_1 = PCA(n_components=1)
print("\n\n################# PCA: 2D to 1D ###################\n",pca_1)

pca_1.fit(X)

print("\nExplained variance ratio:\n",pca_1.explained_variance_ratio_)

X_trans_1 = pca_1.transform(X)

X_reduced_1 = pca_1.inverse_transform(X_trans_1)
print("\nInverse transformed X:\n", X_reduced_1)
plt.plot(X_reduced_1[:, 0], X_reduced_1[:, 1], 'bx')
plt.title('Inverse Transformed Data (PCA 2D to 1D)')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.show()

################################### Visualizing the PCA algorithm ###################################
"""
Let's define  10 points in the plane and use them as an example to visualize how we can compress this points in 1 dimension. 
You will see that there are good ways and bad ways.
"""
X = np.array([[-0.83934975, -0.21160323],
       [ 0.67508491,  0.25113527],
       [-0.05495253,  0.36339613],
       [-0.57524042,  0.24450324],
       [ 0.58468572,  0.95337657],
       [ 0.5663363 ,  0.07555096],
       [-0.50228538, -0.65749982],
       [-0.14075593,  0.02713815],
       [ 0.2587186 , -0.26890678],
       [ 0.02775847, -0.77709049]])



p = figure(title = '10-point scatterplot', x_axis_label = 'x-axis', y_axis_label = 'y-axis') ## Creates the figure object
p.scatter(X[:,0],X[:,1],marker = 'o', color = '#C00000', size = 5) ## Add the scatter plot

## Some visual adjustments
p.grid.visible = False
p.outline_line_color = None 
p.toolbar.logo = None
p.toolbar_location = None
p.xaxis.axis_line_color = "#f0f0f0"
p.xaxis.axis_line_width = 5
p.yaxis.axis_line_color = "#f0f0f0"
p.yaxis.axis_line_width = 5

# ## Initialize notebook mode for Plotly and Bokeh
# py.init_notebook_mode()
# output_notebook()

## Shows the figure
show(p)

# ## Plot widget
# plot_widget()







################################### Visualization of a 3-dimensional dataset ###################################
"""In this section we will see how some 3 dimensional data can be condensed into a 2 dimensional space. """
from pca_utils import random_point_circle, plot_3d_2d_graphs
X = random_point_circle(n = 150)
print(f"\nX.shape = {X.shape}\nX[:5] = {X[:5]}\n")
deb = plot_3d_2d_graphs(X)
deb.update_layout(yaxis2 = dict(title_text = 'test', visible=True))
deb.show()





################################### Using PCA in Exploratory Data Analysis ###################################
print("\n###################### Using PCA in Exploratory Data Analysis ######################\n")
"""
Let's load a toy dataset with  500 samples and  1000 features.
"""
df = pd.read_csv("C3_W2/toy_dataset.csv")

print(df.head())
print(f"\nShape of the toy dataset, df.shape: {df.shape}\n")



# Let's try to see if there is a pattern in the data. 
# The following function will randomly sample 100 pairwise tuples (x,y) of features, so we can scatter-plot them.
def get_pairs(n = 100):
    from random import randint
    i = 0
    tuples = []
    while i < 100:
        x = df.columns[randint(0,999)]
        y = df.columns[randint(0,999)]
        while x == y or (x,y) in tuples or (y,x) in tuples:
            y = df.columns[randint(0,999)]
        tuples.append((x,y))
        i+=1
    return tuples

pairs = get_pairs()

fig, axs = plt.subplots(10,10, figsize = (35,35))
i = 0
for rows in axs:
    for ax in rows:
        ax.scatter(df[pairs[i][0]],df[pairs[i][1]], color = "#C00000")
        ax.set_xlabel(pairs[i][0])
        ax.set_ylabel(pairs[i][1])
        i+=1
plt.show()
"""
It looks like there is not much information hidden in pairwise features. Also, it is not possible to check every combination, 
due to the amount of features. 
"""
# Let's try to see the linear correlation between them.
corr = df.corr()

## This will show all the features that have correlation > 0.5 in absolute value. We remove the features 
## with correlation == 1 to remove the correlation of a feature with itself
mask = (abs(corr) > 0.5) & (abs(corr) != 1)
print(corr.where(mask).stack().sort_values())
"""The maximum and minimum correlation is around  0.631 and -0.632. This does not show too much as well."""






print("\n###################### PCA decomposition to compress our data(100D) into a 2-dimensional subspace (plane) ######################\n")
#Let's try PCA decomposition to compress our data into a 2-dimensional subspace (plane) so we can plot it as scatter plot.
# Loading the PCA object
pca = PCA(n_components = 2) # Here we choose the number of components that we will keep.

X_pca = pca.fit(df)
print("\nExplained variance ratio:\n",pca.explained_variance_ratio_)

X_pca = pca.fit_transform(df)

df_pca = pd.DataFrame(X_pca, columns = ['principal_component_1','principal_component_2'])
print(f"\nShape of the PCA transformed(1000D to 2D) dataset, df_pca.shape: {df_pca.shape}\n")
print(df_pca.head())


# Let's plot the PCA transformed data
plt.scatter(df_pca['principal_component_1'],df_pca['principal_component_2'], color = "#C00000")
plt.xlabel('principal_component_1')
plt.ylabel('principal_component_2')
plt.title('PCA decomposition')
plt.show()
"""This is great! We can see well defined clusters."""

# pca.explained_variance_ration_ returns a list where it shows the amount of variance explained by each principal component.
print("\nTotal explained variance ratio:",sum(pca.explained_variance_ratio_))
""" we preserved only around 14.6% of the variance!"""

"""Quite impressive! We can clearly see clusters in our data, something that we could not see before. 
How many clusters can you spot? 8, 10?

If we run a PCA to plot 3 dimensions, we will get more information from data.
"""
print("\n###################### PCA : 100D to 3D ######################\n")
pca_3 = PCA(n_components = 3).fit(df)
X_t = pca_3.transform(df)
df_pca_3 = pd.DataFrame(X_t,columns = ['principal_component_1','principal_component_2','principal_component_3'])

import plotly.express as px
fig = px.scatter_3d(df_pca_3, x = 'principal_component_1', y = 'principal_component_2', z = 'principal_component_3').update_traces(marker = dict(color = "#C00000"))
fig.show()
print("\nTotal explained variance ratio:",sum(pca_3.explained_variance_ratio_),"\n")