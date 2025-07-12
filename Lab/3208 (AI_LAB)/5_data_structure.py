list1 = [1,2,3,4]
list2 = [True,False,True,False]
list3 = list2.copy()

list2.insert(2,5)
list2.extend(list1)

print(list2)



list4 = list1
list4[0] = 10
print(list1)
list4 = list1.copy()
list4[0] = 100
print(list1)



print("\n\n\n")
####### Tupple #######

tup1 = (1,"AI",True)
#tup1[0] = 10 # tupples are immutable
print(tup1)

tup1_list = list(tup1)
tup1_list[0] = 10
print(tup1_list)
print(tup1)


print("\n\n\n")
####### Set #######

set1 = {1,2,3,4,5}
set2 = {3,4,5,6,7}
print(set1) 
print(type(set1)) 
print(set1.union(set2)) #
print(set1.intersection(set2)) #
print(set1.difference(set2)) # set1 - set2
print(set1.difference_update(set2)) # set1 = set1 - set2
print(set1.symmetric_difference(set2)) # set1 + set2 - set1.intersection(set2)
print(set1.issubset(set2))
print(set1.issuperset(set2))
print(set1.isdisjoint(set2))
print(set1.add(6))
print(set1.remove(6))
print(set1.discard(6))
print(set1.pop())
print(set1.clear())
print(set1)

set1 = {} # this is a dictionary
set1 = set() # this is a set


print("\n\n\n")
####### Dictionary #######

dict1 = {"name":"Ali","age":25,"isStudent":True} # key:value pair(2-tupple)
print(dict1) 
print(type(dict1))
print(dict1["name"]) # key based access
print(dict1.get("age")) # key based access
print(dict1.keys()) # list of keys
print(dict1.values()) # list of values
print(dict1.items()) # list of key-value pairs
print(dict1.pop("age")) # remove key-value pair



print("\n\n\n")
####### functions #######

def function(a, b):
    line = "The subject is {} and for {}"
    print(line.format(a,b))
    print(f"The subject is {a} and for {b}")

function("AI","everyone")


print("\n\n\n")

def func1(*args): # variable length arguments. args is a tuple
    #print(args)
    for arg in args:
        print(arg)

list1 = [1,2,3,4]
tupple = (1, "EMon")
dic1 = {"name":"Ali","age":25,"isStudent":True}
func1(list1, tupple, dic1)


print("\n\n\n")
def func2(**args): # variable length keyword arguments. args is a dictionary
        for key, value in args.items():
            print(key, value)   

func2(name="Ali", age=25, isStudent=True)


print("\n\n\n")
def func3(*args, **kwargs): # variable length arguments and keyword arguments
    for arg in args:
        print(arg)
    for key, value in kwargs.items():
        print(key, value)

