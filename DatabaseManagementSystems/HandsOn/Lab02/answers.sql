set echo on;
set serveroutput on;


spool answers.dat
--1. Change the selling price of ‘1.44 floppy drive to Rs.1150.00
update product_master set sell_price=1150.00 where lower(description) like '1.44 floppy drive';

--2.Delete the record with client 0001 from the client master table.
delete from client_master where client_no='0001';


--3.Change the city of client_no’0005’ to Bombay.
update client_master set city='Bombay' where client_no='0005';

--4.Change the bal_due of client_no ‘0001, to 1000.
update client_master set bal_due=1000 where client_no='0001';


--5.Find the products whose selling price is more than 1500 and also find the new selling price as original selling price *15.
select sell_price*15 as new_sell_price from product_master where sell_price>1500;


select sell_price as old_sell_price, sell_price*15 as new_sell_price from product_master where sell_price>1500;


--6. Find out the clients who stay in a city whose second letter is a.
 select name,city from client_master where city like '_a%';


--7. Find out the name of all clients having ‘a’ as the second letter in their names.
 select name from client_master where name like '_a%';


--8. List the products in sorted order of their description. By default order is ascending.
 select product_no from product_master order by description;



--9. Count the total number of orders
--Nothing to do 


--10. Calculate the average price of all the products.
select avg(sell_price) from product_master;


--11. Calculate the minimum price of products.
 select min(sell_price) from product_master;



--12. Determine the maximum and minimum prices . Rename the tittle as ‘max_price’ and min_price respectively.
 select min(sell_price) as min_price, max(sell_price) as max_price from product_master;


--13. Count the number of products having price greater than or equal to 1500.
 select count(*) from product_master where sell_price>=1500;




 select count(sell_price) from product_master;


 update product_master set sell_price=null where description ='Monitors';


 select count(sell_price) from product_master;



 select count(NVL(sell_price,0)) from product_master;


 update product_master set sell_price='12000'  where description ='Monitors';


spool off;

exit;
