import cx_Oracle
con=cx_Oracle.connect("staff/staff@localxe")
cur=con.cursor()
py_Out=cur.var(cx_Oracle.NUMBER)
cur.callproc('sp_Check_SupplierID',['S1001',py_Out])
OutValue=py_Out.getvalue()
if OutValue==0:
	print("Supplier not found")
else:
	print("Supplier found")
con.commit()
con.close()