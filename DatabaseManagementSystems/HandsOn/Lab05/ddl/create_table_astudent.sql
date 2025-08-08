create table astudent (student_id number(6),student_name varchar2(20),dept_id number(6), primary key(student_id), foreign key (dept_id) references adepartment);
