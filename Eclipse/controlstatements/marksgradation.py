maths, physics, chemistry = [float(x) for x in input("Enter marks scored for math, physics and chemistry separated by space:").split()]

average = int((maths+physics+chemistry)/3)

if(maths <35 or physics <35 or chemistry<35):
    print("You have FAILED in the exam.",end='')
    print("You have failed in ",end='')
    if maths <35:
        print("Math",end='')
    if physics <35:
        print(" Physics",end='')
    if chemistry < 35:
        print(" Chemistry")
else:
    print("You have passed the exam")
    if average <=59:
        grade='C'
    elif average <=69:
        grade='B'
    else:
        grade = 'A'
    
    print("Passing grade is", grade, "and average scored is %.2f"%((maths+physics+chemistry)/3))
