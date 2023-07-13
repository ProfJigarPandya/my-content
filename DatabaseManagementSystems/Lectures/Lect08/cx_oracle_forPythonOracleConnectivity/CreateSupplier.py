import cx_Oracle
con=cx_Oracle.connect("staff/staff@localxe")
cur=con.cursor()
cur.execute("""CREATE TABLE supplier(
		supplierid VARCHAR2(6) PRIMARY KEY,
		suppliername VARCHAR2(30),
		suppliercontactno varchar2(15),
		supplieremailid VARCHAR2(30)
		)
			""")
con.commit()
con.close()