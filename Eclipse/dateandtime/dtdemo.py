import time, datetime

epochsec = time.time()
print(epochsec)

t = time.ctime(epochsec)
print(t)

dt = datetime.datetime.today()
print(dt)
print('Current Date: {}/{}/{}'.format(dt.day, dt.month, dt.year))
print('Current Time: {}:{}:{}'.format(dt.hour, dt.minute, dt.second))