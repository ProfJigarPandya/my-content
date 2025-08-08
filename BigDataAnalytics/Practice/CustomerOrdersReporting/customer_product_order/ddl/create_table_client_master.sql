set serveroutput on
set echo on
set time on
set timing on

set termout off

DEFINE dynamic_filename = idle
COLUMN which_dynamic NEW_VALUE dynamic_filename

SELECT 'clien_master'||'_'||TO_CHAR(SYSDATE,'DD_MON_YYYY_HH24MISS')||'.lst' which_dynamic FROM dual;

set termout on

spool &dynamic_filename

drop table client_master;

create table client_master
  (client_no varchar2(6),
  name varchar2(20),
  address1 varchar2(30),
  address2 varchar2(30),
  city varchar2(15),
  state varchar2(15),
  pincode number(6),
  bal_due number(10,2));

spool off;

exit;
