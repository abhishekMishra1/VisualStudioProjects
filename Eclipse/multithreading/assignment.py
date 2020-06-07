from threading import *

class PrintNumbers:
    def __init__(self,type):
        self.type = type
        
    def printSeries(self):
        print(current_thread().getName())
        if self.type == 0: #All natural numbers
            for i in range(1,101):print(i)
        elif self.type == 1: #All odd natural numbers
            for i in range(1,101,2):print(i)
        elif self.type == 2: #All even natural numbers
            for i in range(2,101,2):print(i)


p1 = PrintNumbers(0)
p2 = PrintNumbers(1)
p3 = PrintNumbers(2)

t1 = Thread(target=p2.printSeries)
t2 = Thread(target=p3.printSeries)

p1.printSeries()
t1.start()
t2.start()