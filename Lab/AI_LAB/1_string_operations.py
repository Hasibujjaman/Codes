course = "Artificial Intelligence"
course = course.replace("Intelligence", "Learning")
print(course)
print(course.capitalize()) # Capitalize the first letter
print(course.upper())
print(course.lower())

print(course.lstrip('L')) # Remove the left side of the string
print(course.rstrip('g')) # Remove the right side of the string
# print(course.title())
# print(course.swapcase())
print(course.count("i"))
# print(course.startswith("Art"))
# print(course.endswith("ing"))
print(course.find("i")) # if not found, it will return -1
print(course.index("i")) # if not found, it will throw an exception
# print(course.rfind("i"))
print(course.isalpha()) # if the string contains only alphabets
print(course.isnumeric()) # if the string contains only numbers
print(course.isalnum()) # if the string contains only alphabets and numbers
# print(course.isdecimal())
# print(course.isdigit())
# print(course.isidentifier())
# print(course.islower())
# print(course.isupper())
# print(course.isspace())
# print(course.istitle())
# print(course.join("AI"))
# print(course.split())

