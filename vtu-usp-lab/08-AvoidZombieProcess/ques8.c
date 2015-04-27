#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		printf ("Error : fork \n");
	}
	else if (pid == 0)
	{
		if ((pid = fork()) < 0)
			printf ("Error : fork \n");
		else if (pid > 0)
			exit(0);
		else 
		{
			sleep(2);
			printf ("\nSecond forked process. PID = %d, Parent's PID = %d\n", getpid(), getppid());
			exit(0);
		}			
	}
	else 
	{
		waitpid(pid, NULL, 0);
		system ("ps -o pid,ppid,state,tty,comm");
		exit(0);
	}

	return 0;
}
