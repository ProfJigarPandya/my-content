create or replace procedure student_users
AUTHID CURRENT_USER AS
begin
for i in 1..7
loop
				/*execute immediate 'drop user ce' || to_char(i) || ' cascade';*/
                execute immediate 'create user ce' || to_char(i) || ' identified by ce' || to_char(i) ;
                execute immediate 'grant create session,create view, connect, resource to ce' || to_char(i);
        end loop;
end;

