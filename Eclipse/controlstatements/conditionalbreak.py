x=int(input("Enter a number:"))
for i in range(0,x):
    if(i%10 == 0):
        continue
    elif i > 100:
        break
    print(i,' ',end='')
