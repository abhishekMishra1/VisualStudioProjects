lst=[20,32, 40, 244, 255]
print(type(lst))

b=bytes(lst)
print(type(b))
print(b)
#b[1] = 4 #TypeError: 'bytes' object does not support item assignment

b1=bytearray(lst)
print(type(b1))
print(b1)

b1[1]=32
print(b1)
