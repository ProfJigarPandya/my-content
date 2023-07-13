drop trigger tr_smanagewhenjoined;

create or replace trigger tr_smanagewhenjoined
BEFORE
insert or update on "SECURITYMAN"
for each row
begin 
  if inserting then
    :NEW.joining_date := sysdate;
    :NEW.agewhenjoined := floor(months_between(sysdate, :NEW.dob)/12);
 end if;
 
 if updating then
  :NEW.agewhenjoined := floor(months_between(:OLD.joining_date, :NEW.dob)/12);
 end if;
 
end;

  