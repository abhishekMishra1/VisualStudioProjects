dict1={1:'ram', 2:'laxman', 3:'sita'}
print(dict1)

print(dict1.items())

k=dict1.keys()
for i in k:
    print(i)
    
print(dict1.values())
print(dict1[2])
del dict1[1]
print(dict1)