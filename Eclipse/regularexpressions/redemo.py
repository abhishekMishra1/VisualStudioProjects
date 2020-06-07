import re
str = 'Take 1 43 up 1-3-2020 one 4 idea. one idea at a 43 time only 2-05-2020'

result = re.search(r'o\w\w', str)

print(result.group)

result = re.findall(r'o\w\w', str)
print(result)

result = re.match(r'T\w\w', str)
print(result.group())

result = re.split(r'\d+', str)
print(result)

result = re.sub(r'one', 'Two', str)
print(result)

result = re.findall(r'o\w+', str)
print(result)

result = re.findall(r'o\w?', str)
print(result)

result = re.findall(r'o\w*', str)
print(result)

result = re.findall(r'o\w{1}', str)
print(result)

result = re.findall(r'o\w{1}', str)
print(result)

result = re.findall(r'o\w{2}', str)
print(result)

result = re.findall(r'o\w{3}', str)
print(result)

result = re.findall(r'o\w{1,3}', str)
print(result)

result = re.findall(r'\d{1,2}-\d{1,2}-\d{4}', str)
print(result)
