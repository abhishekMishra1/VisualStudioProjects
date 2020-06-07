import pickle,student

f = open('student.dat','wb')
s = student.Student(123, 'Abhishek', 89)
pickle.dump(s,f)
f.close()