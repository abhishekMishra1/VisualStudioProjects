lst = [10,30, '43',43]
print(lst)
print(lst[2:4])
print(lst*6)
print(len(lst))
print(lst)

lst.append(('hello'))
print(lst)


lst.remove(('hello'))
print(lst)

lst.remove('43')
lst.insert(40,3)
lst.insert(1, 65)
print(lst)

print(max(lst))
print(min(lst))

lst.sort(reverse=True)
print(lst)

del(lst[1])
print(lst)

lst.sort()
print(lst)

lst.clear()
print(lst)