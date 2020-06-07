import logging

logging.basicConfig(filename="mylog.log",level=logging.DEBUG)

a,b = [int(x) for x in input("Enter 2 numbers:").split()]

try:
    f = open("myfile.txt",'w')
    c = a/b
    f.write("Writing %d into the file"%c)
    
    print(c)
except ZeroDivisionError:
    print('Division by zero is not allowed')
    print('Please enter a non zero number')
else:
    print('You have entered a non zero number')
finally:
    f.close()
    print("File closed")
print('Code after the exception')