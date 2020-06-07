class Flight:
    def __init__(self,engine):
        self.engine = engine
        
    def startEngine(self):
        self.engine.start()
        

class AirBusEngine:
    def start(self):
        print("Starting AirBus Engine")
        
class BoeingEngine:
    def start(self):
        print("Starting Boeing Engine")
        
ae = AirBusEngine()
f = Flight(ae)
f.startEngine()

be = BoeingEngine()
f = Flight(be)
f.startEngine()