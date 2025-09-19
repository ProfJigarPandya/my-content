#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int n;
	char buff[50];
	//n=read(0,buff,sizeof(buff));//Std input keyboard
	//n=read(1,buff,sizeof(buff));//Std output screen
	n=read(2,buff,sizeof(buff));//Std error screen
	write(1,buff,n);//Std output screen
}
/*
Surprisingly this program works if you even read from "1"


jmpandya@jigar:.../FilesAndDirectories$ ./undrstndinout.o 1>data.txt
jmpandya@jigar:.../FilesAndDirectories$ cat data.txt
jmpandya@jigar:.../FilesAndDirectories$ gcc -Wall undrstndinout.c -o undrstndinout.o
jmpandya@jigar:.../FilesAndDirectories$ ./undrstndinout.o 1>data.txt
Hello
jmpandya@jigar:.../FilesAndDirectories$ cat data.txt 
Hello
jmpandya@jigar:.../FilesAndDirectories$ 

My logic to understand this behavior is as follows:
	1. When we do ./undrstndinout.o 1>data.txt, the shell forwards stdout to data.txt file.
	2. So when we do read(0,buff,sizeof(buff)), it reads from stdin which is keyboard.
	3. When we do write(1,buff,n), it writes to stdout which is now data.txt file.
	4. So the program works as expected.
	
	But why it works even if we do read(1,buff,sizeof(buff)).	
	I think it works because when we do read(1,buff,sizeof(buff)), 
	it reads from stdout programmatically but the system internally forwards typed from keyboard to diplay.
	
*/