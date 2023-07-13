alter table adepartment 
add (faculty_id number(6), foreign key (faculty_id) references afaculty);
