from abc import abstractclassmethod, ABC

class BMW(ABC):
    def __init__(self,make,model,year):
        self.make=make
        self.model=model
        self.year=year
        
    def start(self):
        print("Starting the engine...")
    def stop(self):
        print("Stopping the engine...")
        
    @abstractclassmethod
    def drive(self):
        pass
        
        
class ThreeSeries(BMW):
    def __init__(self,cruiseControlEnabled, make, model, year):
        super().__init__(make, model, year)
        self.cruiseControlEnabled = cruiseControlEnabled

    def start(self):
        print("Button start. ",end='')
        super().start()
    
    def drive(self):
        print("Three Series is being driven")


        
class FiveSeries(BMW):
    def __init__(self,parkingAssistEnabled, make, model, year):
        BMW.__init__(self, make, model, year)
        self.parkingAssistEnabled = parkingAssistEnabled
        
    def drive(self):
        print("Five Series is being driven")

ThreeSeries = ThreeSeries(True,"BMW",'328i','2018')
print(ThreeSeries.cruiseControlEnabled)
print(ThreeSeries.make)
print(ThreeSeries.model)
print(ThreeSeries.year)
ThreeSeries.start()
ThreeSeries.drive()
ThreeSeries.stop()
print()
    
    
FiveSeries = FiveSeries(True,"BMW",'528i','2019')
print(FiveSeries.parkingAssistEnabled)
print(FiveSeries.make)
print(FiveSeries.model)
print(FiveSeries.year)
FiveSeries.start()
FiveSeries.drive()
FiveSeries.stop()