/*
 Write a C program to create parent and child processes which will communicate with each other using pipes.
  (Use of pipe system call) 

 John and Marry communicate to each other. 

 John initiates the communication. i.e. Parent goes first.

 Routines to let a parent and child synchronize 

 apue - Stevens and Rago - 2nd edition. 
	Example 8.13 (process control pg. 230), 
	Example 10.24 (signals pg. 337), 
	Example 15.7 (ipc pg.507)
 Let parent and child take a call one after another. Parent prints 1. Child prints 0.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static void charatatime(char *str);//Think why static

void TELL_2WAIT();
void TELL_2CHILD(pid_t pid);
void WAIT_4PARENT();

void TELL_2PARENT();
void WAIT_4CHILD(pid_t pid);

static	int 	pfd1[2], //let use pipe#1 for message from John to Marry 
		pfd2[2]; //let use pipe#2 for message from Marry to John
int main()
{
	pid_t pid;


	TELL_2WAIT();
	
	if((pid=fork())<0)
	{
		printf("\n Fork failed ");
		exit(1);
	}
	else if(pid>0)			//Parent - let be process named John
	{			//John writes to pipe1
		close(pfd1[0]);//close the read end of pipe#1
		close(pfd2[1]);//close the write end of pipe#2
		while(1)
		{
			charatatime("1\n");
			TELL_2CHILD(pid);
			WAIT_4CHILD(pid);
		}
	}
	else //Child - let be process named Marry
		//Marry writes to pipe2
	{
		
		close(pfd1[1]);//close the write end of pipe#1
		close(pfd2[0]);//close the read end of pipe#2
		while(1)
		{
			WAIT_4PARENT();
			charatatime("0\n");
			TELL_2PARENT();
		}
	}	
	

	exit(0);	
}

static void charatatime(char *str)
{
	char *ptr;
	int c;
	
	setbuf(stdout, NULL); //set unbuffered
	for(ptr=str; (c=*ptr++) != 0; )
	{
		putc(c,stdout);
	}
	
}

void TELL_2WAIT()
{

	if(pipe(pfd1))
	{
		printf("\n Pipe1 creation error ");
		exit(1);
	} 
	if(pipe(pfd2))
	{
		printf("\n Pipe2 creation error ");
		exit(1);
	} 
}
void TELL_2CHILD(pid_t pid)
{
	if(write(pfd1[1],"p",1) != 1)
	{
		printf("\n Parent telling to child. write error.");
		exit(1);
	}	
}
void WAIT_4PARENT()
{
	char ch;
	if(read(pfd1[0],&ch,1)!=1)
	{
		printf("\n Child trying to read. error. ");
		exit(1);
	}
	if(ch!='p')
	{
		printf("\n Parent provided wrong information ");
		exit(1);
	}
}
void TELL_2PARENT()
{
	
	if(write(pfd2[1],"c",1) != 1)
	{
		printf("\n Child telling to parent. write error.");
		exit(1);
	}	
}
void WAIT_4CHILD(pid_t pid)
{

	char ch;
	if(read(pfd2[0],&ch,1)!=1)
	{
		printf("\n Parent trying to read. error. ");
		exit(1);
	}
	if(ch!='c')
	{
		printf("\n Child provided wrong information ");
		exit(1);
	}
}

