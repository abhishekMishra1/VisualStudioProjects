'''
Created on May 11, 2020

@author: Home
'''

def decor(fun):
    def inner():
        result=fun()
        return result*2
    return inner

@decor
def num():
    return 5

print(num())
resultfun = decor(num)
print(resultfun())
print(num())
