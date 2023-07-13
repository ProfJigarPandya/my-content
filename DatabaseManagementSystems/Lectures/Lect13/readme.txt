How does oracle name objects i.e. table, etc?
When to use single quote and when to use double quote?
Is Oracle case sensitive on names?

Know the facts:

Oracle by default converts the given name (in lower or upper without special symbols except $,#,_, start with letter, max 30 length) to upper case while creating object.

Then after user may refer to table either lower case or upper case of the object name in queries anywhere. It works same way.

But oracle supports a feature to enable user to create object name with space, other special symbols, etc using double quote enclosed.

When user creates an object using any name surrounded by double quotes, oracle stores the name as provided.

Later anytime user must use double quote enclosure with the typed name as is i.e. case sensitiveness to refer to the same object.

This means ideally table name employee same as EMPLOYEE.

But table named "employee" is different than "emplOYEe" or "EMPLOYEE", etc.


As we now know double quote has a special purpose for names of objects, note that single quote is used for strings as data values. 

Refer to attached log file to see and understand the above topic practically.
