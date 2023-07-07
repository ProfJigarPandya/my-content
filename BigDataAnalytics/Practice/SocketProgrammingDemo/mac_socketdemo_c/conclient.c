#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>


#define MAX 256

int main()
{
	int sockfd,n;
	struct sockaddr_in servaddr;
	struct in_addr cliaddr;
	char mess[MAX],*mess1;
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_port = htons(5103);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
	{
		perror("\nSocket creation error: ");
		exit(1);
	}
	
	if( (connect(sockfd,(const struct sockaddr *)&servaddr,sizeof(servaddr))) == -1 )
	{
		perror("\n Error in connect: ");
		exit(1);
	}
	
	while(1)
	{
		if( ( mess1=fgets(mess,MAX,stdin) ) != NULL )
		{
			write(sockfd,mess,strlen(mess));
		}
		else
		{
			printf("\n You pressed end of file Ctrl+d ");
			break;
		}
		
		if( (n = read(sockfd,mess,MAX) ) >0 )
		{
			mess[n] = 0;
			fputs(mess,stdout);
		}

 	}

	close(sockfd);
	exit(0);
}
