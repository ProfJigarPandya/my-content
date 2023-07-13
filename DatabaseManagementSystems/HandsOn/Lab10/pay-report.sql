rem ***********************************************
rem Purpose : Script to generate Payments Report
rem ***********************************************
rem set break and compute settings
break on report on course skip page on batch skip 2
compute sum of amount on batch course report
set pagesize 24
set linesize 90
set feedback off
column amount format 99,999
column name format a20 heading 'Student Name'
column dj heading 'Date of|Joining'
column dp heading 'Date of|Payment'
ttitle skip 1 right 'Page:' format 99 sql.pno skip 1 center 'Payments Report' skip 2

select c.ccode course, b.bcode batch, p.rollno, s.name name, phone, dj, dp,
amount
from batches b, students s, payments p, courses c
where b.ccode = c.ccode and b.bcode = s.bcode and s.rollno = p.rollno
order by course, batch;

set feedback on
rem clear settings
clear compute
clear break
clear column
ttitle off