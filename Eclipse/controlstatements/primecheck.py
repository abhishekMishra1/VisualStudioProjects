num=int(input("Enter a number:"))

primeFlag=True

for x in range(2, int(num/2)):
    if(num%x==0):
        primeFlag = False 
        break

if(primeFlag):
    print(num,"is Prime")
else:
    print(num,"is not Prime")
