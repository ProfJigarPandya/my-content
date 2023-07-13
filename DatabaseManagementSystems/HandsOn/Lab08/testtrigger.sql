select floor(months_between(sysdate, to_date('01-MAR-1988','DD-MON-YYYY'))/12) from dual;

drop table securityman;


create table securityman 
(id number, name varchar2(20), dob date, agewhenjoined number, joining_date date);

select * from securityman;

@create_trigger.sql;

DELETE FROM SECURITYMAN;

insert into securityman 
(id, name, dob)
values
(1,'James','01-JAN-1997');



insert into securityman 
(id, name, dob)
values
(2,'Karen','01-MAR-1990');


insert into securityman 
(id, name, dob)
values
(3,'Naic','25-APR-1995');



update securityman
set dob=to_date('15-AUG-1993','DD-MON-YYYY')
where id=2;


select * from securityman;





select id, name from securityman;
