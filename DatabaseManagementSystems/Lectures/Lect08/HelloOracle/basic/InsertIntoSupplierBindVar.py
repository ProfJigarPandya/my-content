import cx_Oracle
con=cx_Oracle.connect("staff/staff@localxe")
cur=con.cursor()
supplierID='S1005'
supplierName='Victor Electronics'
supplierContactNo='115-265-4675'
supplierEmailID='victorelectronics@easy.com'
cur.execute("""INSERT INTO supplier VALUES (:1,:2,:3,:4)""",(supplierID,supplierName,supplierContactNo,supplierEmailID))
con.commit()
con.close()