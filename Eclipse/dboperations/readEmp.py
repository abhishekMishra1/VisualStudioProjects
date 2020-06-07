import mysql.connector
conn = mysql.connector.connect(host='localhost',database='mydb',user='root',password='root')
if conn.is_connected():
    print('Connected to mysql db')
    
cursor = conn.cursor()
cursor.execute('select * from emp')
'''
rows = cursor.fetchone()

while rows is not None:
    print(rows)
    rows = cursor.fetchone()
'''
rows = cursor.fetchall()
print('Total number of records:',cursor.rowcount)
for row in rows:
    print(row)
    
cursor.close()
conn.close()