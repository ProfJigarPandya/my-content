Case study on learning cartesian product and natural join using multiple tables and also null records.


Use spool filename at the start and spool off at end to record your work.

I have specifically number comments such a way that I can extract questions using below text filter easily.
grep -e '--[0-9][0-9].' out.log > question.txt

Following the questions, related sql and outupt is shown and also a judgement/answer is mentioned.

Tables Involved:
student record (astudent table) enrolls to department (adepartment table) which is under any faculty (afaculty table).

Note that order of table creation matters when connections are involved. 

Here, first faculty table then department and then only student table shall be created if used ddl right away.

Refer to out.log first with questions and then answers with explaination.

Can you think more topics/questions in the same and try finding answers.
