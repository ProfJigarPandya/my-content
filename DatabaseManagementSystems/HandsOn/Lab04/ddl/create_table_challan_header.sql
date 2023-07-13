create table challan_header
(challan_no varchar2(6) primary key, 
 s_order_no varchar2(6) references sales_order,
 challan_date date not null,
 billed_yn char(1) default );
 
