int1 = 1
int2 = 2
float1 = 1.0
float2 = float(int2)
string1 = "abc"
string2 = "123"

print(int1 + int2)
print(float1 + float2)
print(string1 + string2)
print(float1 + 2) ##auto type conversion, intger 2 converts to float 2.0 automatically
print(int(float1 + float2)) ##forced type conversion, manually done
##print(string2 + 1) ## error, can't convert integer to string implicitly
print(int(string2) + 1) 
print(int(string1) + 1) ##error, strings only made of digits are convertable to integer


