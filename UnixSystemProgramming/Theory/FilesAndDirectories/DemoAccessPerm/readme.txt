jigarpandya@aharnish:~/my-content/UnixSystemProgramming/Theory/FilesAndDirectories/DemoAccessPerm$ ./a.out /bin/ping
 Permission available OK : mode F_OK ==> File exists 
access api : : Permission denied
 Permission available OK : mode R_OK ==> File is readable

jigarpandya@aharnish:~/my-content/UnixSystemProgramming/Theory/FilesAndDirectories/DemoAccessPerm$ sudo ./a.out /bin/ping
[sudo] password for jigarpandya: 
 Permission available OK : mode F_OK ==> File exists 
 Permission available OK : mode R_OK ==> File is readable
 Permission available OK : mode W_OK ==> File is writeable
 Permission available OK : mode X_OK ==> File is executable/explorable
jigarpandya@aharnish:~/my-content/UnixSystemProgramming/Theory/FilesAndDirectories/DemoAccess

===========


-rwsr-xr-x 1 root root 64424 Jun 28  2019 /bin/ping
The s in owner's x place shows that this file is owned by root with set-uid flag.  When any regular user runs it, kernel will swith execution as effective root.


ping 192.168.26.10 running on one tab
ps -aux | grep ping in another tab
jigarpa+ 10630  0.0  0.0  23500  1104 pts/1    S+   17:02   0:00 ping 192.168.26.10


Note that user jigarpandya still able to run the ping command and see the results. 


