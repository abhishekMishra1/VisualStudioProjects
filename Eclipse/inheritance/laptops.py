from abc import abstractclassmethod, ABC

class TouchScreenLaptop(ABC):
    
    @abstractclassmethod
    def scroll(self):
        print('Scrolling enabled.')
    
    @abstractclassmethod
    def click(self):
        pass

class HP(TouchScreenLaptop):
    
    def scroll(self):
        print("HP scrolling")
                

class Dell(TouchScreenLaptop):
    
    def scroll(self):
        print("Dell scrolling")

class HPNotebook(HP):
    
    def click(self):
        print("HPNotebook click")
        
class DellNotebook(Dell):
    
    def click(self):
        print("DellNotebook click")
        
        
hpnotebook = HPNotebook()
dellnotebook=DellNotebook()

hpnotebook.click()
hpnotebook.scroll()

dellnotebook.click()
dellnotebook.scroll()
