s = {23, 43, 54, 'XYS', 23, 42, 43}
print(s)
print(type(s))
print(len(s))

s.update([88,55])
print(s)

s.remove(23)
print(s)
#print(s[0])
#print(s*4)

f=frozenset(s)
print(f)
#f.update([30])
#f.remove([42])