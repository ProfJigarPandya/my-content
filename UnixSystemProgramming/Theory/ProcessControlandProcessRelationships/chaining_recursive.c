/* Chaining of processes. 
 Can verify from process id and parent process id;
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	static int total_chain_nodes=-1, existing_chain_nodes=1;

	if(argc<2)//Program pathname and a number 
	{
		printf("\n Usage: Program <number of nodes>");
		exit(EXIT_FAILURE);
	}
	if(existing_chain_nodes==1)//First node first parent itself
	{
		total_chain_nodes = atoi(argv[1]);
		printf("\n Total Chain nodes expected %d\n", total_chain_nodes);
		if(total_chain_nodes <=0)
		{
			printf("\n Parent is counted minimum one node");
			exit(EXIT_FAILURE);
		}
		printf("getpid()\tgetppid()\texisting_chain_nodes\ttotal_chain_nodes\n");
		printf("\n PARENT: (%d\t%d\t%d\t%d)",getpid(),getppid(),existing_chain_nodes,total_chain_nodes);
		fflush(stdout);
	}
	
	if(existing_chain_nodes==total_chain_nodes)
	{
		printf("\n At terminating condition!");
		fflush(stdout);
		return(EXIT_SUCCESS);
	}
	else
	{
		int wstatus;
		pid_t cpid,w;
		cpid=fork();
		if(cpid==-1)
		{
			perror("\n Fork error ");
			exit(EXIT_FAILURE);
		}
		if(cpid==0)//child
		{
			existing_chain_nodes++;
			printf("\n CHILD: (%d\t%d\t%d\t%d)",getpid(),getppid(),existing_chain_nodes,total_chain_nodes);
			fflush(stdout);
			if(existing_chain_nodes < total_chain_nodes)
				main(argc,argv);		
		}
		else
		{
			//parent to collect status of chile.
			do {
                   		w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
                   		if (w == -1) {
                       			perror("waitpid");
                       			exit(EXIT_FAILURE);
                   		}

                   		if (WIFEXITED(wstatus)) {
                       			printf("exited, status=%d\n", WEXITSTATUS(wstatus));
                   		} else if (WIFSIGNALED(wstatus)) {
                       			printf("killed by signal %d\n", WTERMSIG(wstatus));
                   		} else if (WIFSTOPPED(wstatus)) {
                       			printf("stopped by signal %d\n", WSTOPSIG(wstatus));
                  		} else if (WIFCONTINUED(wstatus)) {
                       			printf("continued\n");
                   		}
               		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
			printf("\n Reaped %d \n",cpid);
		}//end of looping through child status change
	}
	printf("\n At end of main ");
	fflush(stdout);
	return (EXIT_SUCCESS);

}
