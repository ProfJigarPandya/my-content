import cx_Oracle
con=cx_Oracle.connect("staff/staff@xe")
cur=con.cursor()
py_RetValue=cur.callfunc('sf_NoOfSupplier',cx_Oracle.NUMBER)
print("The total number of suppliers are ",py_RetValue)
con.commit()
con.close()