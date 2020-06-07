a=[1,2,3,4]
b=[2,4,6,8]

result=[]

for i in a:
    if i in b:
        result.append(i)
print(result)

result.clear()

result=[i for i in a if i in b]
print(result)