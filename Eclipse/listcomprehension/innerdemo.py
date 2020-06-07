class Car:
    def __init__(self,make, year):
        self.make=make
        self.year=year
        
    def DisplayInfo(self):
        print("Car is of ",self.make)
        print("Manufactured in year", self.year)
            
    class Engine:
        def __init__(self,number):
            self.number = number
        
        def start(self):
            print("Engine started")
            

c = Car("Ford", 2011)
e = c.Engine(123)

c.DisplayInfo()
e.start()