Aim is to learn few maths sqls on math_sample table.

1)
To create table math_sample with only single column idata
./create_math_sample.sh

2)
To load random data into math_sample table. This data is created using c program and redirection to a file in linux.
./sqlldr_math_sample.sh

3)
Now lets learn rename and rownum
You may want to create backup if you wish as below:
create table math_sample_backup as select * from math_sample;


Using below, I added a srno column with prepopulated data using rownum:
./change_maths.sh

4)
Let us learn pl/sql, update and random number generation in oracle:

alter the table with one more column named salary and update salary using random number generation.


alter table math_sample add (salary number(6));

./runplsql.sh


5)
*** See that there are duplicates in idata column because 100 randoms were loaded using c program random function file.

SQL> select count(distinct idata) from math_sample;

COUNT(DISTINCTIDATA)
--------------------
		  68

SQL> select count(all idata) from math_sample;

COUNT(ALLIDATA)
---------------
	    100

SQL>

****
 See that avg([all/distinct] attribute_name)

 By default all is used.

SQL> select avg( idata) from math_sample;

AVG(IDATA)
----------
     51.84

SQL> select avg(distinct idata) from math_sample;

AVG(DISTINCTIDATA)
------------------
	53.0882353

SQL> 
  



6)



Find sql answers to questions listed in question.txt. To get tables client_master and product_master, refer to lab1;
sqlplus jpandya@xe @answers.sql

cat answers.dat
