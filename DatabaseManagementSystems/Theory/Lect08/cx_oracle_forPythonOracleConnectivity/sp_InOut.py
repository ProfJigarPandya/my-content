import cx_Oracle
con=cx_Oracle.connect("staff/staff@xe")
cur=con.cursor()
py_InOut=cur.var(cx_Oracle.STRING)
py_InOut.setvalue(0,'VE1_')
cur.callproc('sp_InOut',[py_InOut])
print(py_InOut.getvalue())
con.commit()
con.close()