set serveroutput on;
DECLARE
   cno client_master.CLIENT_NO%type;
   cname client_master.NAME%type;
   ccity client_master.CITY%type;
   cbalance client_master.BAL_DUE%type;
   CURSOR c_clients is
      SELECT client_no, name, city, bal_due FROM client_master;
BEGIN
   OPEN c_clients;
   LOOP
      FETCH c_clients into cno, cname, ccity, cbalance;
      
      EXIT WHEN c_clients%notfound;
      dbms_output.put_line(cno || ' ' || cname || ' ' || ccity || ' ' || cbalance);
   END LOOP;
   CLOSE c_clients;
END;
/