select * from all_users A where A.USERNAME = 'JPANDYA';

drop user jpandya cascade;
 
CREATE USER jpandya identified by jpandya;

grant create session, create view, connect, resource to jpandya;

create table jpandya.test (id number, name varchar2(50));

insert into jpandya.test (id, name) values (1,'James');

commit;

alter user jpandya identified by jigarpandya;

