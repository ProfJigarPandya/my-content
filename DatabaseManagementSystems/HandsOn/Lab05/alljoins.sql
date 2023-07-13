set serveroutput on;

spool alljoins.out;

select * from astudent order by student_id;

select * from adepartment order by dept_id;

--cartesian product
select * from astudent ast, adepartment adept where ast.dept_id = adept.dept_id;


--natural join
select * from astudent ast natural join adepartment adept;


--normal join also known as inner join
select * from astudent ast inner join adepartment adept on ast.dept_id = adept.dept_id;

select * from astudent ast join adepartment adept on ast.dept_id = adept.dept_id;--by default it is inner or normal join


--left outer join, this includes inner join as well internally
select * from astudent ast left outer join adepartment adept on ast.dept_id=adept.dept_id;

select * from astudent ast left  join adepartment adept on ast.dept_id=adept.dept_id;

select * from astudent ast, adepartment adept where ast.dept_id=adept.dept_id(+); --pad right side columns as null, in other words left join

--right outer join, this includes inner join as well internally
select * from astudent ast right  join adepartment adept on ast.dept_id=adept.dept_id;

select * from astudent ast, adepartment adept where ast.dept_id(+)=adept.dept_id;--pad left side columns as null in other words right join

--full join, inner plus left and right padded with nulls
select * from astudent ast full  join adepartment adept on ast.dept_id=adept.dept_id;

--Below is not allowed
--select * from astudent ast, adepartment adept where ast.dept_id(+)=adept.dept_id(+); --Error: a predicate may reference only one outer-joined table


--full except the inner
select * from astudent ast full  join adepartment adept on ast.dept_id=adept.dept_id
where ast.dept_id is null or adept.dept_id is null;

-- left join except the inner
select * from astudent ast left join adepartment adept on ast.dept_id=adept.dept_id
where adept.dept_id is null;

-- right join except the inner
select * from astudent ast right join adepartment adept on ast.dept_id=adept.dept_id
where ast.dept_id is null;






spool off;



