Handling date and time differently

Dear Students,

Date (and time) is a crucial information component present everywhere. Database management systems need to record dates as part of metadata as well as data in users table many various places. As we all know date (and time) is universal and has countless history. The timezones and day-light saving concepts with country posed formats bring challenges to computer engineers.

That is 1-2-24 can be seen differently as below:

January 2nd, 1924 or January 2nd, 2024

February 1st, 1924 or February 1st, 2024

Character Functions:

LENGTH, RPAD, LPAD, RTRIM, LTRIM, TRIM, INSTR, REPLACE, etc.

Number Functions:

SIN, ASIN, SINH, COS, ACOS, COSH, TAN, ATAN, ATAN2, TANH, ABS, SIGN, ROUND, TRUNC, etc.

Date Functions:

SYSDATE, SYSTIMESTAMP, ROUND, TRUNC, MONTHS_BETWEEN, ADD_MONTHS, etc.

Conversion Functions and  Other functions.

Note that oracle database supports a virtual table named 'dual' to run sample queries like below:

select sysdate from dual;

Returns the system date.


