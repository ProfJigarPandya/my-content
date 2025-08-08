drop table salesman_master;

create table salesman_master
(salesman_no	varchar2(6) primary key check (salesman_no like '5%'),
 sal_name	varchar2(20) not null,
 address	varchar2(50) not null,
 city	varchar2(20),
 state	varchar2(20),
 pincode	number(6),
 sal_amt	number(8,2) not null check(sal_amt<>0),
 tgt_to_get	number(6,2) not null check(tgt_to_get<>0),
 ytd_sales	number(6,2) not null check(ytd_sales <> 0),
 remarks	varchar2(30));

exit;
