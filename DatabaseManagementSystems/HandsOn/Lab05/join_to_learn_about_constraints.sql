desc student;
desc department;
desc faculty;


select constraint_name, DECODE(CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, table_name, r_constraint_name 
from user_constraints
where table_name='ASTUDENT' or table_name='ADEPARTMENT' or table_name='AFACULTY'
order by 2;


select l.constraint_name, DECODE(l.CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, r.table_name r_table_name
from user_constraints l, user_constraints r
where l.r_constraint_name = r.constraint_name
and l.constraint_type='R'
and l.table_name = 'ASTUDENT'
union
select l.constraint_name, DECODE(l.CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, null r_table_name
from user_constraints l
where l.constraint_type='P'
and l.table_name = 'ASTUDENT';


select l.constraint_name, DECODE(l.CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, r.table_name r_table_name
from user_constraints l, user_constraints r
where l.r_constraint_name = r.constraint_name
and l.constraint_type='R'
and l.table_name = 'ADEPARTMENT'
union
select l.constraint_name, DECODE(l.CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, null r_table_name
from user_constraints l
where l.constraint_type='P'
and l.table_name = 'ADEPARTMENT';

select l.constraint_name, DECODE(l.CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, r.table_name r_table_name
from user_constraints l, user_constraints r
where l.r_constraint_name = r.constraint_name
and l.constraint_type='R'
and l.table_name = 'AFACULTY'
union
select l.constraint_name, DECODE(l.CONSTRAINT_TYPE,'P','PRIMARY KEY','R','REFRENCE KEY', 'Unknown') constraint_type, null r_table_name
from user_constraints l
where l.constraint_type='P'
and l.table_name = 'AFACULTY';