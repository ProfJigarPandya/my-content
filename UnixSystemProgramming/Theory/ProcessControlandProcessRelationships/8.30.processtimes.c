// Figure 8.30.Time and execute all command - line arguments
//pr_exit from Figure 8.5

#include <stdio.h>
#include <sys/times.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

extern int	errno;
void pr_exit(int status);
static void	pr_times(clock_t, struct tms *, struct tms *);
static void	do_cmd(char *);
int
main(int argc, char *argv[])
{
	int		i;
	setbuf(stdout, NULL);
	if(argc==1)
	{
		printf("\n Usage: %s comm1 comm2 ... ",argv[0]);
		exit(1);
	}
	for (i = 1; i < argc; i++)
		do_cmd(argv[i]);/* once for each command-line arg */
	exit(0);
}
static void
do_cmd(char *cmd)
{				/* execute and time the "cmd" */
	struct tms	tmsstart, tmsend;
	clock_t		start , end;
	int		status;
	printf("\ncommand: %s\n", cmd);
	if ((start = times(&tmsstart)) == -1)	/* starting values */
		printf("times error %s", strerror(errno));
	if ((status = system(cmd)) < 0)	/* execute command */
		printf("system() error %s", strerror(errno));
	if ((end = times(&tmsend)) == -1)	/* ending values */
		printf("times error %s", strerror(errno));
	pr_times(end - start, &tmsstart, &tmsend);
	pr_exit(status);
}
static void
pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
	static long	clktck = 0;
	if (clktck == 0)	/* fetch clock ticks per second first time */
		if ((clktck = sysconf(_SC_CLK_TCK)) < 0)
			printf("sysconf error %s",strerror(errno));
	printf(" real: %7.2f\n", real / (double)clktck);
	printf(" user: %7.2f\n",
	       (tmsend->tms_utime - tmsstart->tms_utime) / (double)clktck);
	printf(" sys: %7.2f\n",
	       (tmsend->tms_stime - tmsstart->tms_stime) / (double)clktck);
	printf(" child user: %7.2f\n",
	       (tmsend->tms_cutime - tmsstart->tms_cutime) / (double)clktck);
	printf(" child sys: %7.2f\n",
	       (tmsend->tms_cstime - tmsstart->tms_cstime) / (double)clktck);
}
void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
		       WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
		       WTERMSIG(status),
#ifdef WCOREDUMP
		       WCOREDUMP(status) ? " (core file generated)" : "");
#else
		       "");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
		       WSTOPSIG(status));
}
