'''
Created on 26-Dec-2016

@author: CE DDU
'''
import cx_Oracle
con=cx_Oracle.connect("staff/staff@localxe")
cur=con.cursor()
cur.execute("""Select * from supplier""")
print(cur.fetchall())
con.commit()
con.close()