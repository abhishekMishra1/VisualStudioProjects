class Student:
    major = 'CSE'
    
    def __init__(self,rollno, name):
        self.rollno = rollno
        self.name = name
        
    def Display(self):
        print(self.name)
        print(self.major)
        print(self.rollno)

s1 = Student(1,'Abhishek')
s2 = Student(2,'Mohit')

s1.Display()
s2.Display()
print(Student.major)
#print(Student.name) #AttributeError: type object 'Student' has no attribute 'name'

