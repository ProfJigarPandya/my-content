set echo on;

spool answers.dat

select name from client_master;

select name, city from client_master;


select product_no, description from product_master;


select name from client_master where lower(city)='bombay';


select * from client_master
  where client_no in ('0001','0002');


select * from product_master
  where lower(description) in ('1.44 drive','1.22 drive');
  
  
select * from product_master
where sell_price > 5000;


select name from client_master where lower(city) in ('bombay','delhi','madras');



select * from product_master
where sell_price > 2000 and sell_price<=5000;


select name, city, state from client_master where lower(state) not in ('maharashtra');

spool off;

exit;
