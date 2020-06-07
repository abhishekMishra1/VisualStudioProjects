import mysql.connector
conn = mysql.connector.connect(host='localhost',database='mydb',user='root',password='root')
if conn.is_connected():
    print('Connected to mysql db')
    
cursor = conn.cursor()
try:
    cursor.execute("insert into emp values(3,'Neeraj',8000)")
    conn.commit()
    print('Recorded added')
except:
    conn.rollback()


cursor.close()
conn.close()