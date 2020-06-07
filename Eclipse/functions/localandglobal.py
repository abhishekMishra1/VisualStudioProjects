x=123

def display():
    x=75
    print(x)
    print(globals()['x'])

print(x)
display()
z=display
z()
z()