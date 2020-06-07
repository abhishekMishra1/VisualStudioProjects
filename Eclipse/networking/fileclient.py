import socket

s = socket.socket()

s.connect(('localhost',1001))

fileName = input('Enter file name:')

s.send(fileName.encode())
content = s.recv(1024)

print(content.decode())

s.close()