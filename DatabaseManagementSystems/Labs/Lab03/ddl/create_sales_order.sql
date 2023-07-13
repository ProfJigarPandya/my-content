drop table sales_order;

create table sales_order
(s_order_no varchar2(6) primary key check(s_order_no like '0%'),
s_order_date date,
client_no varchar2(25) references client_master(client_no),
dely_add varchar2(6),
salesman_no varchar2(6) references salesman_master(salesman_no),
dely_type char(1) default 'f' check (dely_type in ('p','f')),
billed_yn char(1), 
dely_date date,
order_status varchar2(25) check (order_status in ('inprocess','fullfilled','backorder','cancelled')),
check (dely_date>=s_order_date)
);

exit;
