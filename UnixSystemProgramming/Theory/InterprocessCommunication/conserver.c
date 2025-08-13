/* concurrent echo server which displays the IP when gets connect to any client
	and receives - sends back the received thing ECHO to the client.
	
   	
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define MAX 28
int main()
{
 int listenfd,confd,n;
 struct sockaddr_in servaddr,cliaddr;
 socklen_t len=sizeof(cliaddr);
 char mess[MAX];

 bzero(&servaddr,sizeof(servaddr));
 servaddr.sin_family = AF_INET;
 servaddr.sin_port = htons(5102);
 //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_addr.s_addr = inet_addr("192.168.28.11");

 if( (listenfd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
 {
	perror("\n Error in socket creation ");
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
	if( ( confd = accept(listenfd,&cliaddr,&len)) < 0 )	 
	{
		perror("\n Unable to accept on socket ");
		exit(1);
	}
	
	fputs("\n Child server:-   Client",stdout);
	//printf(" %s connected\n",inet_ntoa(cliaddr));
	
	if(fork() == 0)   // child server
	{
		close(listenfd);
		
		while( ( n=read(confd,mess,MAX) ) >0 )
		{
			mess[n] = 0;
			write(confd,mess,strlen(mess));		
		}
		//fputs((char *)inet_ntoa(cliaddr),stdout);
		fflush(stdout);
		perror("        client Terminated");	
		
		close(confd);	
		exit(0);//important to terminate connection		
	}
  close(confd);	
 }//end of infinite loop
    
}// end of main
