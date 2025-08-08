set serveroutput on;

set echo on;

spool answers.log

--1. Find the product_no and description of non- moving products.
select product_no, description from product_master;

select product_no, description from product_master where product_no not in (select distinct product_no from sales_order_details);

select distinct product_no from sales_order_details;

--2. Find the customer name, address, city and pincode for the client who has placed order no “019001”
select client_no from sales_order where s_order_no='019001';

select name, address1, address2, city, pincode from client_master where client_no in (select client_no from sales_order where s_order_no='019001');

--3. Find the client names who have placed order before the month of may 96.

--Know this, if you insert date year with two digit year i.e. format RR as 15 then from 00 to 49 are assumed to be in the 21st centure. Hence, it will be stored as 2015. While RR values ranging from 50 to 99 are assumed to be in the 20th century (1950 through 1999).

--When I inserted I did not focus on this and hence my database contains year 2096 instead of 1996.

--Lets first fix that.

--For below, I don't know its 1996 or 2096, so I applied to_char with YYYY.

select s_order_no, client_no, s_order_date from sales_order;

select s_order_no, client_no, to_char(s_order_date,'DD-MON-YYYY') from sales_order;

--Applied string functions by oracle to retrieve 19XX.

SELECT TO_CHAR( 
    to_date( SUBSTR(TO_CHAR(s_order_date,'DD-MON-YYYY'),1,7)
    ||'19'
    ||SUBSTR(TO_CHAR(s_order_date,'DD-MON-YYYY'),10,2))
    ,'DD-MON-YYYY') FROM sales_order;


--Lets update using this intermediate result logic.
update sales_order
set s_order_date=(to_date( SUBSTR(TO_CHAR(s_order_date,'DD-MON-YYYY'),1,7)
    ||'19'||SUBSTR(TO_CHAR(s_order_date,'DD-MON-YYYY'),10,2)));


select to_char(s_order_date,'DD-MON-YYYY') from sales_order;


select client_no, to_char(s_order_date,'DD-MON-YYYY') from sales_order where s_order_date<to_date('01-MAY-1996','DD-MON-YYYY');



--4. Find out if product “1.44 Drive” is ordered by only client and print the client_no name to whom it was sold.

select count(*) from sales_order_details where product_no in (select product_no from product_master where description='1.44 Drive');


select cm.client_no, cm.name from client_master cm, sales_order so, sales_order_details sod where so.s_order_no=sod.s_order_no and cm.client_no=so.client_no and sod.product_no in (select product_no from product_master where description='1.44 Drive');


--5. find the names of client who have placed orders worth Rs.10000 or more.

select name from client_master where client_no in (select so.client_no from sales_order so, sales_order_details sod where so.s_order_no=sod.s_order_no group by so.client_no having sum(sod.qty_order*sod.product_rate)>=10000);





--6. Select the orders placed by ‘Rahul Desai”

select so.s_order_no from sales_order so, client_master cm
    where so.client_no=cm.client_no
    and cm.name='Rahul Desai';


select so.s_order_no from sales_order so, client_master cm
    where so.client_no=cm.client_no
    and cm.name='Ivan';


select s_order_no from sales_order where client_no=(select distinct client_no from client_master where name='Ivan')
    ;


select s_order_no, client_no, 'Ivan' name from sales_order where client_no=(    select client_no from client_master where name='Ivan');



--7. Select the names of persons who are in Mr. Pradeep’s department and who have also worked on an inventory control system.





--8. Select all the clients and the salesman in the city of Bombay.

  (select sal_name name, 'salesman' title from salesman_master where lower(city)='bombay')
    union
    (select name name, 'client' title from client_master where lower(city)='bombay' )
    order by title;


--union vs union all (* union all allows duplicate). Note in below Ravi is client as well as salesman both.

  select sal_name from salesman_master where lower(city)='bombay';


select name from client_master where lower(city)='bombay';


select sm.sal_name from salesman_master sm
where sm.salesman_no in ( select so.salesman_no from client_master cm, sales_order so, salesman_master sm where cm.client_no=so.client_no and sm.salesman_no=so.salesman_no and lower(sm.city)='bombay' and lower(cm.city)='bombay' group by so.salesman_no);
--Having is not required as sales_order will have entries for orders and we are discussing clients and salesmen involved in placing orders.)

--10. Select the product_no, description, qty_on-hand,cost_price of non_moving items in the product_master table.

select product_no, description, qty_on_hand, cost_price from product_master where product_no not in (select distinct product_no from sales_order_details);

spool off;

exit;
