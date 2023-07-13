CREATE or REPLACE PROCEDURE sp_Check_SupplierID (p_supID IN supplier.supplierID%Type, p_out OUT NUMBER)
AS
v_count number(3);
BEGIN
select count(*) into v_count from supplier where supplierID = p_supID;
if(v_count=0) then
	p_out:=0;
	return;
end if;
p_out:=1;
return;
END;