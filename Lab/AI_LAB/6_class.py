class Student:
    name = ""
    age = 0

    # def __init__(self,name,age):
    #     print("Constructor Called")
    #     self.name = name
    #     self.age = age


    def setDet(self,name,age):
        self.name = name
        self.age = age
    
    def showDet(self):
        print("Name: ",self.name)
        print("Age: ",self.age)

s1 = Student()
s1.setDet("Ali",25)
s1.showDet()
    


### Inheritance
class Subject(Student):
   pass

