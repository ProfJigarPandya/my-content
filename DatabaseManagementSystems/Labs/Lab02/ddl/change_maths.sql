


create table math_sample2 as select rownum as srno, idata from math_sample;


drop table math_sample;

rename math_sample2 to math_sample;

exit;
