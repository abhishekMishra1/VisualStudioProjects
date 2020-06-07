import mysql.connector

def deleteRecord(ID):
    conn = mysql.connector.connect(host='localhost',database='mydb',user='root',password='root')
    if conn.is_connected():
        print('Connected to mysql db')
        
        cursor = conn.cursor()
        sqlcomm = "delete from emp where id='%d'"
        args =(ID)
        try:
            cursor.execute(sqlcomm % args)
            conn.commit()
            print('Employee record deleted with id', ID)
        except:
            conn.rollback()
        finally:
            cursor.close()
            conn.close()
            
empId = int(input('Enter employee id:'))
deleteRecord(empId)