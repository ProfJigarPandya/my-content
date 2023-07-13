set serveroutput on
set echo on



DECLARE
	d number(3);
BEGIN
	
	FOR d IN 1 .. 101 LOOP
		update math_sample set salary=(select dbms_random.value(1,10000) from dual) where srno=d;
		dbms_output.put_line('Value of d is ' || d);
	END LOOP;
END;
/

exit;
