/* dateclient.c ......... gets date from dateserver.c and displays on screen */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
 int sockfd,n;
 char mess[28];
 struct sockaddr_in s_adr;
 socklen_t len;
 
 bzero(&s_adr,sizeof(s_adr));
 s_adr.sin_family = AF_INET;
 s_adr.sin_port = htons(5113);
 s_adr.sin_addr.s_addr = htonl(INADDR_ANY);

if( ( sockfd = socket(AF_INET,SOCK_STREAM,0) ) < 0)
{
	perror("\n Error in Socket ");
	exit(0);
}
  
if( connect(sockfd,(struct sockaddr*)&s_adr,sizeof(s_adr)) < 0)
{
	perror("\n Error in conect ");
	exit(1);
}
 
while( ( n = read(sockfd,(char *)mess,25)) >0 )
  {
   mess[n]=0;
   fputs(mess,stdout);
  }


 if(n<0)
 {
   perror("\n Error in reading ");
 }
 close(sockfd);
 exit(0);

}

