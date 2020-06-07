class Patient:
    def setID(self,id):  # @ReservedAssignment
        self.__id = id
    def getID(self):
        return self.__id
    
    def setName(self,name):
        self.__name = name
    def getName(self):
        return self.__name
    
    def setSSN(self,ssn):
        self.__ssn = ssn
    def getSSN(self):
        return self.__ssn
    
p1 = Patient()
p1.setID(1)
p1.setName('Raju')
p1.setSSN(4819231)

p2 = Patient()
p2.setID(2)
p2.setName('Nimesh')
p2.setSSN(4819233)

lst = [p1,p2]

for x in lst:
    print(x.getID())
    print(x.getName())
    print(x.getSSN())
    print()