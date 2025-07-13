from sympy import symbols, diff
import sympy as sp



J = (3)**2
J_epsilon = (3 + 0.001)**2
k = (J_epsilon - J)/0.001    # difference divided by epsilon
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k:0.6f} ")

#Let's see what happens if we make  𝜖 smaller
J = (3)**2
J_epsilon = (3 + 0.000000001)**2
k = (J_epsilon - J)/0.000000001
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k} ")


###################### Finding symbolic derivatives ####################
#Define the python variables and their symbolic names.
J, w = symbols('J, w')
#Define and print the expression
J=w**2
sp.init_printing()
J

#Use SymPy's diff to differentiate the expression for  𝐽 with respect to  𝑤
dJ_dw = diff(J,w)
dJ_dw

#Evaluate the derivative at a few points by 'substituting' numeric values for the symbolic values. In the first example,  𝑤 is replaced by  2
dJ_dw.subs([(w,2)])    # derivative at the point w = 2
dJ_dw.subs([(w,3)])    # derivative at the point w = 3
dJ_dw.subs([(w,-3)])    # derivative at the point w = -3

w, J = symbols('w, J')
J = 2 * w
J
dJ_dw = diff(J,w)
dJ_dw
dJ_dw.subs([(w,-3)])    # derivative at the point w = -3
#Compare this with the arithmetic calculation
J = 2*3
J_epsilon = 2*(3 + 0.001)
k = (J_epsilon - J)/0.001
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k} ")


#Another example
J, w = symbols('J, w')
J=w**3
J
dJ_dw = diff(J,w)
dJ_dw
dJ_dw.subs([(w,2)])   # derivative at the point w=2
#Compare results
J = (2)**3
J_epsilon = (2+0.001)**3
k = (J_epsilon - J)/0.001
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k} ")


#Another example
J, w = symbols('J, w')
J= 1/w
J
dJ_dw = diff(J,w)
dJ_dw
dJ_dw.subs([(w,2)])
#Compare results
J = 1/2
J_epsilon = 1/(2+0.001)
k = (J_epsilon - J)/0.001
print(f"J = {J}, J_epsilon = {J_epsilon}, dJ_dw ~= k = {k} ")


