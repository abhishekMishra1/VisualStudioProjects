lstCountries = ['Bharat', 'Nepal', 'Srilanka']
print(lstCountries)

lstCountries.append('Thailand')
print(lstCountries)

del lstCountries[1]
print(lstCountries)

lstCountries.insert(1, 'Nepal')
print(lstCountries)

setCountries = set(lstCountries)
print(setCountries)

#setCountries.append('Thailand') #AttributeError: 'set' object has no attribute 'append'
#print(setCountries)

#del setCountries[1] #TypeError: 'set' object doesn't support item deletion
#print(setCountries)

#setCountries.insert(1, 'Nepal') #AttributeError: 'set' object has no attribute 'insert'
#print(setCountries)
