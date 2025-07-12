#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define PAGER "${PAGER:-more}" /* environment variable, or default */
#define MAXLINE 255
int main(int argc, char *argv[])
{
	char	line[MAXLINE];
	FILE	*fpin, *fpout;
	if (argc != 2)
	{
		printf("usage: a.out <pathname>");
		exit(1);
	}
	if ((fpin = fopen(argv[1], "r")) == NULL)
	{
		printf("can't open %s", argv[1]);
		exit(1);
	}

	if ((fpout = popen(PAGER, "w")) == NULL)
	{
		printf("popen error");
		exit(1);
	}
	
	/* copy argv[1] to pager */
	while (fgets(line, MAXLINE, fpin) != NULL) 
	{
		if (fputs(line, fpout) == EOF)
		{
			printf("fputs error to pipe");	
			exit(1);
		}
	}
	
	if (ferror(fpin))
	{
		printf("fgets error");
		exit(1);
	}

	if (pclose(fpout) == -1)
	{
		printf("pclose error");
		exit(1);
	}

	exit(0);
}
