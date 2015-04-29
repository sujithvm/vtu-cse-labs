#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	
	if (pid < 0) printf ("Error : fork() \n");
	else if (pid == 0) _exit(0);
	else 
	{
		sleep(2);
		system("ps -o pid,ppid,stat,tty,comm");
	}

	return 0;
}

