from datetime import *


d = date(2019,7,23)
t = time(12,43)

dt = datetime.combine(d,t)

print(dt)