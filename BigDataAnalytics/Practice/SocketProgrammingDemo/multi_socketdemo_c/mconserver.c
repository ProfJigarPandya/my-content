/* concurrent echo server which displays the IP when gets connect to any client
	and receives - sends back the received thing ECHO to the client.


*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>


#define MAX 256
int main(int argc, char* argv[])
{
 int listenfd,confd,n;
 struct sockaddr_in servaddr;
 struct in_addr cliaddr;
 socklen_t len=sizeof(cliaddr);
 char mess[MAX];

 bzero(&servaddr,sizeof(servaddr));
 servaddr.sin_family = AF_INET;
 servaddr.sin_port = htons(5103);
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

 if(argc<2)
 {
     printf("\n Usage: client.o serverip");
		 exit(1);
 }

 if( (listenfd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
 {
	perror("\n Error in socket creation ");
	exit(1);
 }


 if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr)<=0)
 {

	 perror("\nSocket ip address attach error: ");
	 exit(1);
 }

 if( (bind(listenfd,(struct sockaddr*) &servaddr,sizeof(servaddr))) == -1 )
 {
	perror("\n Error in binding ");
	exit(1);
 }

 listen(listenfd,5);

 for(;;)
 {
	if( ( confd = accept(listenfd,(struct sockaddr *) &cliaddr,&len)) < 0 )
	{
		perror("\n Unable to accept on socket ");
		exit(1);
	}

	fputs("\n Child server:-   Client",stdout);
	printf(" %s connected\n",inet_ntoa(cliaddr));

	if(fork() == 0)   // child server
	{
		close(listenfd);

		while( ( n=read(confd,mess,MAX) ) >0 )
		{
			mess[n] = 0;
			write(confd,mess,strlen(mess));
		}
		fputs((char *)inet_ntoa(cliaddr),stdout);
		fflush(stdout);
		perror("        client Terminated");

		close(confd);
		exit(0);//important to terminate connection
	}
  close(confd);
 }//end of infinite loop

}// end of main
