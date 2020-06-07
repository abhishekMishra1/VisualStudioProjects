class ObjectCounter:
    numberOfObjects = 0
    
    def __init__(self):
        ObjectCounter.numberOfObjects+=1
        
    @staticmethod
    def DisplayCount():
        print(ObjectCounter.numberOfObjects)
        

o1 = ObjectCounter()
o4 = ObjectCounter()
o2 = ObjectCounter()
o3 = ObjectCounter()
o5 = ObjectCounter()

ObjectCounter.DisplayCount()