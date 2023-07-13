--Objective : Answer the following Questionstions
--Q1. Create an index on the table client_master, field client_no.
create index in_clientmaster_cn
on client_master(client_no); --Because, client_no is a pk the index already exist.

select * from user_indexes where table_name='CLIENT_MASTER';

select column_name from all_ind_columns
where INDEX_NAME='SYS_C007792';

--Q2. Create an index on the sales_order, field s_order_no.
select * from user_indexes where table_name='SALES_ORDER';

select column_name from all_ind_columns where INDEX_NAME='SYS_C007760';

select column_name from user_indexes ui natural join all_ind_columns 
where table_name='SALES_ORDER';


--Q3. Create an composite index on the sales_order_details table for the columns s_order_no and product_no.
create index ic_sales_order_details
on sales_order_details(s_order_no, product_no);


--Q4. Create an composite index ch_index on challan_header table for the columns challan no and s_order_no.
create index ch_index
on challan_header(challan_no, s_order_no);
--Q5. Create an uniQuestion index on the table salesman_master, field salesman_no.
--Q6. Drop index ch_index on table challan_header.
drop index ch_index;
--Q7. Create view on salesman_master whose sal_amt is less than 3500.
create view startup_salesman
as select * from salesman_master
where sal_amt < 3500;

select * from salesman_master
where sal_amt < 3500;

select * from startup_salesman;

--Q8. Create a view client_view on client_master and rename the columns as name, add1, add2, city, pcode, state respectively.
create view client_view
as
select 
NAME,
ADDRESS1 add1,
ADDRESS2 add2,
CITY,
STATE,
PINCODE pcode from client_master;
--Q9. Select vthe client names from client_view who lives in city ‘Bombay’.
select name from client_view
where lower(city)='bombay';
--Q10. Drop the view client_view.
drop view client_view;

