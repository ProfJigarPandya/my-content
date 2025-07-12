(Use of dup system call)

 dup() duplicates an existing object descriptor and returns its value to the calling process

     (fildes2 = dup(fildes)).  The argument fildes is a small non-negative integer index in the per-

     process descriptor table.  The value must be less than the size of the table, which is returned

     by getdtablesize(2).  The new descriptor returned by the call is the lowest numbered descriptor

     currently not in use by the process.
