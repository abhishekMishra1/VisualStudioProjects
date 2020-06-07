class Student:
    def __init__(self):
        self.__id=123
        self.__name="Abhishek"
        
    def display(self):
        print(self.__id)
        print(self.__name)
        
s = Student()
#print(s.__id) #AttributeError: 'Student' object has no attribute '__id'
#print(s.__name)
s.display()
print(s._Student__id)#hidden object can be accessed like this. This is name mangling
print(s._Student__name)