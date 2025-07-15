#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX 28

int main()
{
	int sockfd,n;
	struct sockaddr_in servaddr,cliaddr;
	char mess[MAX],*mess1;
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_port = htons(5102);
	servaddr.sin_family = AF_INET;
	//servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_addr.s_addr = inet_addr("192.168.28.11");
	
	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
	{
		perror("\nSocket creation error: ");
		exit(1);
	}
	
	if( (connect(sockfd,&servaddr,sizeof(servaddr))) == -1 )
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
