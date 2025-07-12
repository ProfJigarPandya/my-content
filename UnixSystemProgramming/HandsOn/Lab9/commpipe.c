/*
  Write a C program to create parent and child processes which will communicate with each other using pipes.
  Parent process writes static message to child. Data is processed via a pipe.

  Parent/writeto (1)  -->---- Child/readfrom (0)
                      -->----
  Use dup to forward it to sort utility.

*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>

extern int errno;

int main(void)
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "Hello, Kids!\nToday is a rainy day.\nAll schools remain closed because of bad weather.\nTake care of yourself.";
        char    readbuffer[80];

        if(pipe(fd)==-1)
	{	
		printf("\n pipe error: %s\n",strerror(errno));
		exit(1);
	}
        
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid != 0)
        {
                /* Parent process closes up read side of pipe */
                close(fd[0]);//read end

                /* Send "string" through the write side of pipe */
                write(fd[1], string, (strlen(string)+1));
        }
        else
        {
                /* Child process closes up write side of pipe */
                close(fd[1]);//write end
		
		
                /* Read in a string from the pipe */
                //nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                //printf("Child: Received string: %s", readbuffer);


		/* Close up standard input of the child */
                close(0);
                
                /* Duplicate the input side of pipe to stdin */
                dup(fd[0]);

		//                dup2(0, fd[0]);


                execlp("sort", "sort", NULL);
                exit(0);
        }
        
        return(0);
}
