/*
Copy standard input to standard output using library calls.
*/

#include <stdio.h>
int main()
{
	char ch;
	while((ch=getc(stdin))!=EOF)
	{
		putc(ch,stdout);
	}
	printf("\n Have a nice day!!");
	return(0);
}
