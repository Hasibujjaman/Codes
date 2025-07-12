age = int(input("Enter your age: "))

if age < 18:
    if age < 0:
        print("You are not born yet\n")
    else:
        print("You are a child\n")

elif age >= 18 and age < 60:
    print("You are an adult\n")   

else:
    print("You are dead\n")


