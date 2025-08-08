import cx_Oracle
con=cx_Oracle.connect("staff/staff@xe")
cur=con.cursor()
cur.execute("""Select * from supplier""")
print(cur.fetchall())
con.commit()
con.close()