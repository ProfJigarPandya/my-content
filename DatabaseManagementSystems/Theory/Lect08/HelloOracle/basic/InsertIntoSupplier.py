import cx_Oracle
con=cx_Oracle.connect("staff/staff@localxe")
cur=con.cursor()
cur.execute("""INSERT INTO supplier VALUES ('S1001','Giant Store','203-237-2097','rachel1@easy.com')""")
cur.execute("""INSERT INTO supplier VALUES ('S1002','EBATs','115-340-2345','ebats@easy.com')""")
cur.execute("""INSERT INTO supplier VALUES ('S1003','Shop Zilla','203-123-3456','shopzilla@easy.com')""")
cur.execute("""INSERT INTO supplier VALUES ('S1004','VV Electronics','115-340-6756','vvelectronics@easy.com')""")
con.commit()
con.close()