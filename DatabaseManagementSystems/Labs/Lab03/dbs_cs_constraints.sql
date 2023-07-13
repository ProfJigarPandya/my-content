create table ports
(port_id number,
 port_name varchar2(20),
 country varchar2(20),
 capacity number,
 constraint port_pk primary key (port_id));
 
select constraint_name, constraint_type from user_constraints
where table_name='PORTS';

select * from user_cons_columns
where table_name='PORTS';

DROP TABLE SHIPS;

create table ships
(ship_id number,
 ship_name varchar2(20),
 home_port_id number references ports(port_id));--inline constraint

select constraint_name from user_constraints where table_name='SHIPS'; 

 
alter table ships
drop constraint SYS_C007914;

alter table ships
add constraint fk_home_port_id foreign key (home_port_id) references ports(port_id) ON DELETE CASCADE;

select constraint_name from user_constraints where table_name='SHIPS'; 

select * from user_constraints
where table_name='SHIPS';

select * from user_cons_columns
where table_name='SHIPS';

delete from ports;

select * from ports;

insert into ports (port_id,port_name, country, capacity ) values(1,'Baltimore','USA',2);
insert into ports (port_id,port_name, country, capacity ) values(2,'Charleston','USA',2);
insert into ports (port_id,port_name, country, capacity ) values(3,'Tampa','USA',8);
insert into ports (port_id,port_name, country, capacity ) values(4,'Miami','USA',6);
insert into ports (port_id,port_name, country, capacity ) values(5,'Galveston','USA',4);

insert into ships (ship_id, ship_name, home_port_id) values (1, 'Codd Crystal', 1);
insert into ships (ship_id, ship_name, home_port_id) values (2, 'Codd Elegance', 3);
insert into ships (ship_id, ship_name, home_port_id) values (3, 'Codd Champion', 4);
insert into ships (ship_id, ship_name, home_port_id) values (4, 'Codd Victorious', 4);
 
select * from ships;

alter table ships
add constraint pk_ships_shipid primary key (ship_id);

select * from user_constraints
where table_name = 'SHIPS';

insert into ships (ship_id, ship_name, home_port_id) values (NULL, 'Codd Victorious', 4);


insert into ships (ship_id, ship_name, home_port_id) values (5, 'Codd Unknown Port', NULL); 

alter table ships
modify home_port_id not null;

delete from ships where home_port_id is null;


alter table ships
modify home_port_id not null;
 
select * from ships natural join ports; --no common column, hence returned all results.

select ship_id, ship_name, port_id, port_name, country, capacity from ships inner join ports on ships.home_port_id=ports.port_id;


create table ships_nat as select * from ships;

select * from user_constraints where table_name ='SHIPS_NAT';
select * from user_constraints where table_name ='SHIPS';

alter table ships_nat
add constraint pk_ships_nat primary key (ship_id);

alter table ships_nat
rename column home_port_id to port_id;

alter table ships_nat
add constraint fk_ships_nat_hpi foreign key (port_id) references ports(port_id);

select * from ships_nat natural join ports; 
