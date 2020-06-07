class Programmer:
    def setName(self,name):
        self.name = name
        
    def getName(self):
        return self.name
    
    def setSalary(self,s):
        self.salary = s
        
    def getSalary(self):
        return self.salary
    
    def setTechnologies(self,techs):
        self.technologies = techs
        
    def getTechnologies(self):
        return self.technologies
    
    
p1 = Programmer()
p1.setName('Abhishek')
p1.setSalary(10000)
p1.setTechnologies(['C','C++','Java','Python'])

print(p1.getName())
print(p1.getSalary())
print(p1.getTechnologies())
