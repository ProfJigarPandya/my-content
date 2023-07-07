set serveroutput on
set echo on
set time on
set timing on

set termout off 

DEFINE dynamic_filename = idle
COLUMN which_dynamic NEW_VALUE dynamic_filename

SELECT 'product_master'||'_'||TO_CHAR(SYSDATE,'DD_MON_YYYY_HH24MISS')||'.lst' which_dynamic FROM dual;

set termout on

spool &dynamic_filename


drop table product_master;

create table product_master
  (product_no varchar2(20),
  description varchar2(20),
  profit_percent number,
  unit_measure varchar2(20),
  qty_on_hand number,
  reorder_lvl number,
  sell_price number,
  cost_price number);

spool off;

exit;

