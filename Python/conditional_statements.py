x = input("Enter x = ")
x = int(x)
if x == 0 : print("x is zero")
if x >= 1 : 
    print("x is positive")
##indentation determines the scope in python
if x < 0 :
    print("x is not zero")
    if x < -1 :
        print("x is not -1")
        print("x is less than -1")