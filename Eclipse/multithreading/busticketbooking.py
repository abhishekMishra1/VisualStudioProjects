from threading import * 

class BookMyBusTickets:
    
    def __init__(self,totalseats):
        self.totalseats = totalseats
        self.l = Lock()
        #self.l = Semaphore()
    def buyTicket(self, requestedseats):
        print()
        print('Total seats available now:', self.totalseats)
        self.l.acquire()
        if requestedseats <= self.totalseats:
            print('Confirming the ticket')
            print('Processing the payment')
            print('Printing the ticket')
            self.totalseats -= requestedseats
        else:
            print('Sorry, no more seats available!!')
        self.l.release()    

obj = BookMyBusTickets(10)
t1 = Thread(target=obj.buyTicket,args=(2,))
t2 = Thread(target=obj.buyTicket,args=(1,))
t3 = Thread(target=obj.buyTicket,args=(5,))
t4 = Thread(target=obj.buyTicket,args=(2,))

t1.start()
t2.start()
t3.start()
t4.start()
