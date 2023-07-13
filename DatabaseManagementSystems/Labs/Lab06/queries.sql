set echo on;

spool result_lab06.log

select * from client_master;
select * from product_master;
select * from salesman_master;
select * from sales_order;
select * from sales_order_details;



--Q1.- Print the description and total quantity sold for each product.
--Here, description is in product master where as quantity sold is in sales_order_details;
select pm.description, sum(sod.qty_disp)
from product_master pm, sales_order_details sod
where pm.product_no=sod.product_no
group by pm.description;
--We should have better grouped by pm.product_no because description is not a uniq attribute.




--Q2.- Find the value of each product sold.
select pm.description, sum(sod.qty_disp*product_rate)
from product_master pm, sales_order_details sod
where pm.product_no=sod.product_no
group by pm.description;



--Q3.- Calculate the average quantity sold for each client that has a maximum order value of 15000.
--Here, interest is to find out customers who need to be given more promotions as they are not using the site enough. 

select b.name,a.aqsold from
(select so.client_no, avg(sod.qty_disp) aqsold
from sales_order so, sales_order_details sod
where so.s_order_no=sod.s_order_no
group by so.client_no
having sum(sod.product_rate*sod.qty_order) <= 15000) a, client_master  b
where a.client_no=b.client_no;

--Other way lets find out premium customers, who are already ordering a  lot.
select b.name,a.aqsold from
(select so.client_no, avg(sod.qty_disp) aqsold
from sales_order so, sales_order_details sod
where so.s_order_no=sod.s_order_no
group by so.client_no
having sum(sod.product_rate*sod.qty_order) > 15000) a, client_master  b
where a.client_no=b.client_no;



--Q4.- Find out the products which has been sold to Ivan.
select b.product_no, b.description, a.totalq
from
(
select sod.product_no, sum(sod.qty_disp) totalq
from client_master cm, product_master pm, sales_order so, sales_order_details sod
where cm.client_no = so.client_no
and cm.name='Ivan'
and so.s_order_no=sod.s_order_no
and pm.product_no=sod.product_no
group by sod.product_no
) a,
product_master b
where a.product_no=b.product_no
order by a.product_no;

--Q4.- Find out the products which has been sold to Ivan.

select sod.product_no, pm.description
from client_master cm, product_master pm, sales_order so, sales_order_details sod
where cm.client_no = so.client_no
and cm.name='Ivan'
and so.s_order_no=sod.s_order_no
and pm.product_no=sod.product_no;

SELECT DISTINCT description
FROM product_master
WHERE product_no IN
  (SELECT product_no
  FROM sales_order_details
  WHERE s_order_no IN
    (SELECT s_order_no
    FROM sales_order
    WHERE client_no IN
      (SELECT client_no FROM client_master WHERE name='Ivan'
      )
    )
  );


--Q5.- Find the names of clients who have ‘CD Drive’.
select b.name, a.totalq
from
(
select so.client_no, sum(sod.qty_disp) totalq
from product_master pm, sales_order so, sales_order_details sod
where pm.description='CD Drive'
and so.s_order_no=sod.s_order_no
and pm.product_no=sod.product_no
group by so.client_no
) a,
client_master b
where a.client_no=b.client_no
order by b.client_no;



--Q6.- Find the products and their quantities for the orders placed by ‘Vandana’ and ‘Ivan’.
select b.description, a.tq
from
(select sod.product_no, sum(sod.qty_disp) tq
from  sales_order so,sales_order_details sod
where so.s_order_no=sod.s_order_no
and so.client_no in (select client_no from client_master where name in ('Vandana','Ivan'))
group by sod.product_no) a, product_master b
where a.product_no=b.product_no
;



--Q7.- Select product_no, total qty_ordered for each product.
select sod.product_no, sum(sod.qty_order)
from sales_order_details sod
group by sod.product_no
order by 2 desc;


--Q8.- Select product_no, product description and qty ordered for each product.
select a.pno, b.description, a.qto
from
(select sod.product_no pno, sum(sod.qty_order) qto
from sales_order_details sod
group by sod.product_no) a, product_master b
where a.pno=b.product_no
order by 3 desc;


--Q9.- Display the order number and day on which clients placed their order.
select so.s_order_no, to_char(so.s_order_date,'DAY')
from  sales_order so
order by so.client_no;


--Q10.- Display the month and Date when the order must be delivered.
select so.s_order_no, to_char(so.dely_date,'MON-DD-yyyy') delivery_date
from  sales_order so 
order by so.client_no;



spool off;

exit;
