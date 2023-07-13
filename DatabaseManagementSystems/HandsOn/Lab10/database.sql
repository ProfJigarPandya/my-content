create table  courses 
( 
   ccode   varchar2(5)  constraint courses_pk  primary key, 
   Name   varchar2(30) constraint courses_name_u unique, 
   Duration    number(3)    constraint courses_duration_chk  check( duration >= 1), 
   fee          number(5)   constraint courses_fee_chk  check( fee >= 0 ), 
   Prerequisite varchar2(100) 
);

create table  faculty 
( 
   fCODE Varchar2(5) constraint faculty_pk  primary key, 
   Name varchar2(30), 
   qual varchar2(30), 
   exp  Varchar2(100)  
);

create table  course_faculty 
( 
   fcode   varchar2(5) constraint course_faculty_fcode_fk references faculty(fcode), 
   CCODE   Varchar2(5) constraint course_faculty_ccode_fk references courses(ccode), 
   grade   char(1)  constraint course_faculty_grade_chk check ( upper(grade) in ('A','B','C') ), 
   constraint course_faculty_pk  primary key(ccode,fcode) 
);

create table batches 
( 
   bCODE   Varchar2(5) constraint batches_pk primary key, 
   ccode   varchar2(5) constraint batches_ccode_fk  references courses(ccode),
   fcode   varchar2(5) constraint baches_fcode_fk references faculty(fcode), 
   stdate  date     constraint batches_stdate_nn not null, 
   enddate date, 
   timing  number(1)   constraint batches_timing_chk check( timing in (1,2,3) ), 
   constraint batches_dates_chk  check ( stdate <= enddate) 
);

create table students 
( 
   rollno   number(5)   constraint students_pk primary key, 
   bcode    varchar2(5) constraint students_bcode_fk  references batches(bcode), 
   name     varchar2(30), 
   gender   char(1)      constraint students_gender_chk check( upper(gender)  in ('M','F')), 
   dj       date, 
   phone    varchar2(10), 
   email    varchar2(30) 
);

create table payments 
( 
   rollno    number(5) constraint payments_rollno_fk references students(rollno), 
   dp        date      constraint payments_dp_nn  not null, 
   amount    number(5) constraint payments_amount_chk check ( amount > 0 ), 
   constraint payments_pk primary key (rollno,dp)
);

insert into courses values('ora','Oracle database',25,4500,'Windows'); 
insert into courses values('vbnet','VB.NET',30,5500,'Windows and  
programming'); 
insert into courses values('c','C programming',20,3500,'Computer Awareness'); 
insert into courses values('asp','ASP.NET',25,5000,'Internet and programming'); 
insert into courses values('java','Java Language',25,4500,'C language'); 
insert into courses values('xml','XML Programming', 15, 4000, 'HTML,Scripting, 
ASP/JSP');

insert into faculty values('gk','George Koch','MS Computer Science','15 years 
with databases');
insert into faculty values('da','Dan Appleman','CS and EE graduate', 
'Extensively worked with COM'); 
insert into faculty values('hs','Herbert Schildt','MS Computer Science', 'Author 
of several books'); 
insert into faculty values('dh','David Hunter','MS Electronics', 'Extensively 
worked with Internet Tehnologees'); 
insert into faculty values('sw','Stephen Walther','Ph.D. in Philosophy', 
'Extensively worked with Internet Tehnologees'); 
insert into faculty values('kl','Kevin Loney', 'MS Eletronics', 'Specialized in 
Oracle DBA'); 
insert into faculty values('jj','Jamie Jaworski','Bachlors of Electrical' 
,'Developed programs for US defense department'); 
insert into faculty values('jc','Jason Couchman','OCP DBA','Published articles 
on Oracle');

insert into course_faculty values('gk','ora','A'); 
insert into course_faculty values('kl','ora','A'); 
insert into course_faculty values('jc','ora','A'); 
insert into course_faculty values('da','vbnet','A'); 
insert into course_faculty values('sw','asp','A'); 
insert into course_faculty values('da','asp','B'); 
insert into course_faculty values('hs','c','A'); 
insert into course_faculty values('dh','xml','A'); 
insert into course_faculty values('jj','java','A');
insert into course_faculty values('hs','java','B');
insert into course_faculty values('jj','c','A'); 
insert into course_faculty values('jj','vbnet','B');
insert into batches values('b1','ora','gk','12-jan-2001','20-feb-2001', 1); 
insert into batches values('b2','asp','da','15-jan-2001','5-mar-2001', 2); 
insert into batches values ('b3','c','hs','20-jan-2001','27-feb-2001',3); 
insert into batches values ('b4','xml','dh','2-mar-2001','30-mar-2001', 3); 
insert into batches values ('b5','java','hs','5-apr-2001','10-may-2001', 1); 
insert into batches values ('b6','vbnet','da','12-july-2001',null,1); 
insert into batches values ('b7','ora','jc','15-aug-2001',null,2);

insert into students values (1,'b1','George Micheal','m','10-jan-2001', 
'488333','gm@yahoo.com'); 
insert into students values (2,'b1','Micheal Douglas','m','11-jan-2001', 
'334333','md@hotmail.com'); 
insert into students values (3,'b2','Andy Roberts','m','11-jan-2001', 
'433554','ar@yahoo.com'); 
insert into students values (4,'b2','Malcom Marshall','m','16-jan-2001', 
'653345','mm@usa.net'); 
insert into students values (5,'b2','Vivan Richards','m','16-jan-2001', 
'641238','vr@yahoo.com'); 
insert into students values (6,'b3','Chirs Evert','f','14-jan-2001', 
null,'ce@yahoo.com'); 
insert into students values (7,'b3','Ivan Lendal','m','15-jan-2001', 
'431212','il@hotmail.com'); 
insert into students values (8,'b4','George Micheal','m','1-mar-2001', 
'488333','gm@hotmail.com');
insert into students values (9,'b5','Richard Marx','m','6-apr-2001', 
'876567','rm@hotmail.com'); 
insert into students values (10,'b5','Tina Turner','f','6-apr-2001', 
'565678','tinat@hotmail.com'); 
insert into students values (11,'b5','Jody Foster','f','7-apr-2001', 
'234344','jody@hotmail.com');

insert into payments values (1,'10-jan-2001',4500);
insert into payments values (2,'11-jan-2001',3500);
insert into payments values (2,'17-jan-2001',1000);
insert into payments values (3,'13-jan-2001',2000);
insert into payments values (3,'20-jan-2001',3000);
insert into payments values (4,'16-jan-2001',3000);
insert into payments values (4,'30-jan-2001',2000);
insert into payments values (5,'16-jan-2001',5000);
insert into payments values (6,'14-jan-2001',3500);
insert into payments values (7,'15-jan-2001',3500);
insert into payments values (8,'1-mar-2001',2000); 
insert into payments values (8,'2-mar-2001',2000); 
insert into payments values (9,'7-apr-2001',3000); 
insert into payments values (10,'10-apr-2001',4500); 
insert into payments values (11,'7-apr-2001',1000);
insert into payments values (11,'10-apr-2001',3500); 
commit;
