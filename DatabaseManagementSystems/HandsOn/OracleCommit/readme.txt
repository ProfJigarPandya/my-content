Commit
Oracle DB has DDL statements immediately commited. Even anything before current DDL will also be committed because current DDL is automatically being committed.

DML statements are NOT automatically committed. So, either special "commit" command or next DDL in the execution will commit DML thus far. 

Shared image shows this story where RHS window can see table immediately but not data until explicit commit.
