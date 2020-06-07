class Student:
    def __init__(self,ID, name, testscore):
        self.ID = ID
        self.name = name
        self.testscore = testscore
        
    def display(self):
        print('Name: %s, ID:%s, Test Score: %s'%(self.name,self.ID,self.testscore))
        
        