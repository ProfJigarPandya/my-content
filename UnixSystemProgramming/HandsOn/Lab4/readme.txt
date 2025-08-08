Programming using opendir, readdir, closedire, etc is a way to learn files and directories implementation in Linux.
[jpandya@localhost lab5]$ pwd
/home/jpandya/MyCourses/OS_2014_15/programs/lab5
[jpandya@localhost lab5]$ mkdir HarivanshBacchan
[jpandya@localhost lab5]$ ls -ld HarivanshBacchan
drwxrwxr-x 2 jpandya jpandya 4096 Jan 19 13:03 HarivanshBacchan
[jpandya@localhost lab5]$ //Why the hard link count is already 2 for a fresh created directory?


[jpandya@localhost lab5]$ mkdir HarivanshBacchan/AmitabhBacchan
[jpandya@localhost lab5]$ ls -ld HarivanshBacchan
drwxrwxr-x ? jpandya jpandya 4096 Jan 19 13:04 HarivanshBacchan
[jpandya@localhost lab5]$ //What shall be count now? Fill the space at '?' above.


[jpandya@localhost lab5]$ mkdir HarivanshBacchan/AmitabhBacchan/AbhishekBacchan
[jpandya@localhost lab5]$ ls -ld HarivanshBacchan
drwxrwxr-x 3 jpandya jpandya 4096 Jan 19 13:04 HarivanshBacchan
[jpandya@localhost lab5]$ //Why count '3' is not changed?


[jpandya@localhost lab5]$ mkdir HarivanshBacchan/AjitabhBachhan
[jpandya@localhost lab5]$ ls -ld HarivanshBacchan
drwxrwxr-x 4 jpandya jpandya 4096 Jan 19 13:06 HarivanshBacchan
[jpandya@localhost lab5]$ //Why is it 4 now?


[jpandya@localhost lab5]$ tree HarivanshBacchan
HarivanshBacchan
|-- AjitabhBachhan
`-- AmitabhBacchan
    `-- AbhishekBacchan

3 directories, 0 files
[jpandya@localhost lab5]$


Hint: . and .. are created by default whenever any directory is created.

In Data Structure, we studied left thread, right thread in threaded binary tree. Can you relate that concept of threading here in Linux files and directory structures?
