Types of files in Linux
1) Regular file

	ls -l output first column shows -

	Text Subtype: i.e HelloWorld.c, Readme.txt
	-rwxrwxrwx 1 jmpandya jmpandya 128 Aug 21 09:05 HelloWorld.c
	

	touch regularfile.txt
  	ls -l regularfile.txt 
	-rwxrwxrwx 1 jmpandya jmpandya 0 Aug 21 08:45 regularfile.txt


	Binary Subtype:  i.e a.out, all linux commands like /usr/bin/touch
	-rwxrwxrwx 1 jmpandya jmpandya 12528 Aug 21 09:06 a.out
	-rwxr-xr-x. 1 root root 73920 Jul  8 05:30 /usr/bin/touch

	Psuedo file system for learning about system and resources
	ls -l /proc/meminfo 
	-r--r--r--. 1 root root 0 Aug 21  2025 /proc/meminfo
	cat /proc/meminfo 
		MemTotal:       16077244 kB
		MemFree:         5305264 kB
		...


2) Directory file

	ls -l output first column shows d
  	mkdir directoryfile
 	ls -ld directoryfile 
	ls -ld directoryfile/
	drwxrwxrwx 1 jmpandya jmpandya 0 Aug 21 08:45 directoryfile

	Directory is ALSO a file only containing details of its contents. i.e. files and subdirectories! A file which can not be directly read in text editors instead there are commands i.e. ls -l dirname and system calls like open to deal with.
	To read information about directory itself
	ls -ld directoryname
	
	Directory conains names of other files and pointers to information on thes files. Only kernel can write directly to a directory type of file.


3) Character Special Files (Also commonly known as device file)

	ls -l output first column shows c

	Providing unbuffered (Variable sized) I/O access units to devices such as printer, displays (tty), etc.

	tty
	ls -l /dev/pts/1
	crw--w----. 1 jmpandya tty 136, 1 Aug 21 08:46 /dev/pts/1

	Psuedo file feature (file consumes data given without growing hard disk space)
	ls -l /dev/null 
	crw-rw-rw-. 1 root root 1, 3 Aug 21 08:37 /dev/null


4) Block Special Files

	ls -l output first column shows b

	Providing bufferred (Fixed size) I/O access units to devices such as disk drives.

	fdisk -l
	ls -l /dev/nvme0n1
	brw-rw----. 1 root disk 259, 0 Aug 21 08:37 /dev/nvme0n1


5) FIFO / Named Pipe (File based Inter Process Communication)

	ls -l output first column shows p


	mkfifo namedpipefile
	ls -l namedpipefile 
	prwxrwxrwx 1 jmpandya jmpandya 0 Aug 21 08:48 namedpipefile
	
	Open two terminal side by side and practice as below orderly:
	Terminal (Right side) 1:
					tail -f namedpipefile
	Terminal (Left side) 2:
					echo "Hello pipe" > namedpipefile
	
	Linux provides unnamed pipe "|" on shell to forward output of a command on left of "|" as input to command on right of "|" symbol. It does not have a name and hence unnamed pipe usage. 

6) Socket (Network based Inter Process Communication)

	ls -l output first column shows s
	
	ls -l /var/run/*.sock

	srw-rw----. 1 root docker 0 Aug 21 08:37 /var/run/docker.sock
	srw-rw-rw-. 1 root root   0 Aug 21 08:37 /var/run/gssproxy.default.sock
	srw-rw-rw-. 1 root root   0 Aug 21 08:37 /var/run/gssproxy.sock
	srw-rw-rw-. 1 root root   0 Aug 21  2025 /var/run/rpcbind.sock


7) Symbolic Link
	ls -l output first column shows l
	
	//Create a hard link. It is NOT any different type of file. It is another name of same file.
   	ln demoactualfile1 demohardlinktofile1
	//Create soft link/shortcut. It is a seperate altogethe a type of file which redirects to destination file.
   	ln -s demoactualfile1 demosoftlinktofile1

	ls -li demoactualfile1 demohardlinktofile1 demosoftlinktofile1 
	30064 -rwxrwxrwx 2 jmpandya jmpandya 11 Aug 21 08:50 demoactualfile1
	30064 -rwxrwxrwx 2 jmpandya jmpandya 11 Aug 21 08:50 demohardlinktofile1
	30065 lrwxrwxrwx 1 jmpandya jmpandya 15 Aug 21 08:51 demosoftlinktofile1 -> demoactualfile1

	Note that inode numbers of actual file 1 and hard link to file1 are same and shows the same type of file, regular (-).
	Whereas soft link is having a seperate inode number and it is a shortcut type of file.
