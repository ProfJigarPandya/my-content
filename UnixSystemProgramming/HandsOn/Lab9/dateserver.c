/* dateserver.c .......... writes system date to confd */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <stdio.h>

int main()
{
 int listenfd,confd,n;
 char mess[28];
 struct sockaddr_in s_adr,client_addr;
 socklen_t len;
 time_t ticks;
 
 bzero(&s_adr,sizeof(s_adr));
 s_adr.sin_family = AF_INET;
 s_adr.sin_port = htons(5113);
 s_adr.sin_addr.s_addr = htonl(INADDR_ANY);

 len = sizeof(client_addr);

 listenfd = socket(AF_INET,SOCK_STREAM,0);
  
 if( bind(listenfd,(struct sockaddr_in *) &s_adr,sizeof(s_adr)) == -1 )
 {
      perror("\n Error in bind ");
     exit(0);
 }

 listen(listenfd,5);

 confd =  accept(listenfd,(struct sockaddr_in *)&client_addr,&len);
 
 ticks = time(NULL);

 snprintf(mess,sizeof(mess),"%.24s\r\n",ctime(&ticks));

 
 write(confd,mess,sizeof(mess));

 /* This is just added as a comment to test subversion functionality */
 close(confd);
 close(listenfd);
 exit(0);

}

