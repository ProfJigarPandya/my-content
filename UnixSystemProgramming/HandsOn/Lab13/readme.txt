Shared memory for ipc
[jpandya@localhost lab7]$ gcc myshareddemo.c
[jpandya@localhost lab7]$ ./a.out

 Segment ID 3768339 shared memory attached at address 0xb7fb3000
segment size: 25600
shared memory reattached at address 0x5000000
READING FROM SHARED: Hello, world. Testing shared memory

[jpandya@localhost lab7]$


[jpandya@localhost lab7]$ ipcs | grep 25600
0x00000000 3768339    jpandya   600        25600      1                       
[jpandya@localhost lab7]$ ipcs

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 2850818    root      644        52         2                       
0x00000000 2883588    root      644        16384      2                       
0x00000000 2916357    root      644        268        2                       
0x00000000 2981894    jpandya   600        393216     2          dest         
0x00000000 3014663    jpandya   600        393216     2          dest         
0x00000000 3047432    jpandya   600        393216     2          dest         
0x00000000 3080201    jpandya   600        393216     2          dest         
0x00000000 3112970    jpandya   600        393216     2          dest         
0x00000000 3145739    jpandya   600        393216     2          dest         
0x00000000 3178508    jpandya   600        393216     2          dest         
0x00000000 3211278    jpandya   600        393216     2          dest         
0x00000000 3244047    jpandya   600        393216     2          dest         
0x00000000 3342352    jpandya   600        393216     2          dest         
0x00000000 3375121    jpandya   600        393216     2          dest         
0x000004d2 3407890    jpandya   600        4096       0                       
0x00000000 3768339    jpandya   600        25600      1                       

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

[jpandya@localhost lab7]$


You may use absolute like IPC_CREAT|0666

or individual flags (grouped as needed) with below constants:

File mode bits:

S_IRWXU
read, write, execute/search by owner
S_IRUSR
read permission, owner
S_IWUSR
write permission, owner
S_IXUSR
execute/search permission, owner
S_IRWXG
read, write, execute/search by group
S_IRGRP
read permission, group
S_IWGRP
write permission, group
S_IXGRP
execute/search permission, group
S_IRWXO
read, write, execute/search by others
S_IROTH
read permission, others
S_IWOTH
write permission, others
S_IXOTH
execute/search permission, others
S_ISUID
set-user-ID on execution
S_ISGID
set-group-ID on execution
S_ISVTX
on directories, restricted deletion flag
