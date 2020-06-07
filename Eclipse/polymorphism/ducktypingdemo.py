class Duck:
    def talk(self):
        print("Quack Quack")
    def swim(self):
        print("Swimming only with legs")
        
class Human:
    def talk(self):
        print("Hello")
    def swim(self):
        print("Swimming with whole body")
        
        
def callTalk(obj):
    obj.talk()
    obj.swim()
    
d=Duck()
callTalk(d)

h=Human()
callTalk(h)