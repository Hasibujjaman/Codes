list1 = ["Artificial", "Intelligence", "Learning"]

for var in list1:
    print(var)

string = "AIL"
for var in string:
    print(var)
print("\n")
for var in string:
    print(var, end="") # end="" will remove the new line character
print("\n")
for var in string:
    print(var, end=" ") # end=" " will add a space between the characters
print("\n")
for num in range(100):
    print(num, end=",")
print("\n")
for num in range(100, 49, -1):
    print(num, end=",")


print("\n\n")
while (int(input("Enter age: ")) > 0 and int(input("Enter age: ")) <100):
    print("You are alive")

