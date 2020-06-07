from threading import Thread, current_thread, main_thread
import time

def displayNumbers():
    print('This thread is',current_thread().getName())
    for i in range(1,11):
        print(i)
        time.sleep(0.2)

t = Thread(target=displayNumbers)
t.start()
time.sleep(1)        

if current_thread().getName() == main_thread().getName():
    print('Main thread in execution')
else:
    print('Some other thread in execution')