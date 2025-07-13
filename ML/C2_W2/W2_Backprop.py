from sympy import *
import numpy as np
import re

import matplotlib.pyplot as plt
from matplotlib.widgets import TextBox
from matplotlib.widgets import Button
import ipywidgets as widgets
from lab_utils_backprop import *

###################### Computation Graph ##########

plt.close("all")
plt_network(config_nw0, "C2_W2/images/C2_W2_BP_network0.PNG")
plt.show()


######## Forward Propagation ########
w = 3
a = 2+3*w
J = a**2
print(f"a = {a}, J = {J}")

############# Backprop ###########
"""Backprop is the algorithm we use to calculate derivatives. As described in the lectures, backprop starts at the right and moves to the left."""
##First node from the right in Computation graph

#Arithmetically
a_epsilon = a + 0.001       # a epsilon
J_epsilon = a_epsilon**2    # J_epsilon
k = (J_epsilon - J)/0.001   # difference divided by epsilon
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_da ~= k = {k} ")
#Symbolically
sw,sJ,sa = symbols('w,J,a')
sJ = sa**2
sJ
sJ.subs([(sa,a)])
dJ_da = diff(sJ, sa)
dJ_da

##Second node

#Arithmetically
w_epsilon = w + 0.001       # a  plus a small value, epsilon
a_epsilon = 2 + 3*w_epsilon
k = (a_epsilon - a)/0.001   # difference divided by epsilon
print(f"a = {a}, a_epsilon = {a_epsilon}, da_dw ~= k = {k} ")
#Symbotically
sa = 2 + 3*sw
sa
da_dw = diff(sa,sw)
da_dw

## Final derivative calculation 

#Symbotically
dJ_dw = da_dw * dJ_da
dJ_dw
#Arithmetically
w_epsilon = w + 0.001
a_epsilon = 2 + 3*w_epsilon
J_epsilon = a_epsilon**2
k = (J_epsilon - J)/0.001   # difference divided by epsilon
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k} ")





##################### Computation Graph of a Simple Neural Network #####################

plt.close("all")
plt_network(config_nw1, "C2_W2/images/C2_W2_BP_network1.PNG")
plt.show()

####### Forward propagation#####

# Inputs and parameters
x = 2
w = -2
b = 8
y = 1
# calculate per step values   
c = w * x
a = c + b
d = a - y
J = d**2/2
print(f"J={J}, d={d}, a={a}, c={c}")

###### Backward propagation (Backprop) ######

##First node from the right in Computation graph 

#Arithmetically
d_epsilon = d + 0.001
J_epsilon = d_epsilon**2/2
k = (J_epsilon - J)/0.001   # difference divided by epsilon
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dd ~= k = {k} ")

#Symbolically
sx,sw,sb,sy,sJ = symbols('x,w,b,y,J')
sa, sc, sd = symbols('a,c,d')
sJ = sd**2/2
sJ
sJ.subs([(sd,d)])
dJ_dd = diff(sJ, sd)
dJ_dd


##Second node

#Arithmetically
a_epsilon = a + 0.001         # a  plus a small value
d_epsilon = a_epsilon - y
k = (d_epsilon - d)/0.001   # difference divided by epsilon
print(f"d = {d}, d_epsilon = {d_epsilon}, dd_da ~= k = {k} ")

#Symbolically
sd = sa - sy
sd
dd_da = diff(sd,sa)
dd_da

#Arithmetically
a_epsilon = a + 0.001
d_epsilon = a_epsilon - y
J_epsilon = d_epsilon**2/2
k = (J_epsilon - J)/0.001   
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_da ~= k = {k} ")

#Symbolically
dJ_da = dd_da * dJ_dd
dJ_da



"""
The steps in backprop
Now that you have worked through several nodes, we can write down the basic method:
working right to left, for each node:

(i)Calculate the local derivative(s) of the node
(ii)Using the chain rule, combine with the derivative of the cost with respect to the node to the right.

* The 'local derivative(s)' are the derivative(s) of the output of the current node with respect to all inputs or parameters.
"""
### Third node

#(i) calculate the local derivatives da_dc, da_db
sa = sc + sb
sa

da_dc = diff(sa,sc)
da_db = diff(sa,sb)
print(da_dc, da_db)
#(ii)
dJ_dc = da_dc * dJ_da
dJ_db = da_db * dJ_da
print(f"dJ_dc = {dJ_dc},  dJ_db = {dJ_db}")


### Fourth(last) node

#(i) calculate the local derivative
sc = sw * sx
sc
print(f"c = {sc}")

dc_dw = diff(sc,sw)
dc_dw
print(f"dc_dw = {dc_dw}")

"""we are not interested in  ∂𝐽/∂𝑥"""

#(ii)
dJ_dw = dc_dw * dJ_dc
dJ_dw
print(f"dJ_dw = {dJ_dw.subs([(sd,d),(sx,x)])}")

##Arithmetically
J_epsilon = ((w+0.001)*x+b - y)**2/2
k = (J_epsilon - J)/0.001  
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k} ")
