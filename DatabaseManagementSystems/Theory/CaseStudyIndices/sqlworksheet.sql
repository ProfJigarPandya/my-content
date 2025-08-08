--truncate table ibm_contracts;


select transaction, awardid, ordernumber, recipientcity
from ibm_contracts
where recipientcity='New York'
; 
--Press F10 to view "Explain Plan" 
--FULL table scan with cost estimate 137


create index in_recipient_city_ic
on
ibm_contracts(recipientcity);

drop index in_recipient_city_ic;

select transaction, awardid, ordernumber, recipientcity
from ibm_contracts
where recipientcity='New York'
;  
--Press F10 to view "Explain Plan"
--Table access by index rowid, range scan out of index in_recipient_city_ic and the cost is 7 only.
 
 
select transaction, awardid, ordernumber, recipientcity
from ibm_contracts
where recipientcity like '%York';--like comparison will not invoke index if wildcard character is in leading position.

 
select transaction, awardid, ordernumber, recipientcity
from ibm_contracts
where recipientcity like 'New%';--like comparison may invoke index as long as wildcard character is not in leading position.
 
select transaction, awardid, ordernumber, recipientcity
from ibm_contracts
where lower(recipientcity)='New York';--here, function lower based index has to be created especially as below.

--not equal never invokes any index.


--Whether the index is promising to optimizer or not has to do with the concept of selectivity.
--If a column tends to include data that is less repetitive and more unique, it is said to have a higher degree of selectivity, and an index on such a column would be
-- more attractive.

create index fbin_recipient_city_ic
on
ibm_contracts(lower(recipientcity));


select index_name, a.* 
from user_indexes a
where table_name = 'IBM_CONTRACTS';

select count(distinct(recipientcity)) from ibm_contracts;--440

select distinct_keys from user_indexes
where table_name = 'IBM_CONTRACTS' AND index_name='IN_RECIPIENT_CITY_IC'; --440

select recipientcity, count(*) c
from ibm_contracts
group by recipientcity;

select * from
user_indexes
where table_name='IBM_CONTRACTS';


select index_name, column_name
from user_ind_columns
where table_name='IBM_CONTRACTS';



--rule of thumb, no more than five indexes on a given table. But choice is yours.

--many times removing unnecessary/unused old indexes help improve application performance.




