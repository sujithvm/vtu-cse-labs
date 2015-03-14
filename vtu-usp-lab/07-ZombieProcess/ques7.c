#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// create process

        pid_t pid = fork();

        if (pid == 0) 
	{
		// child process
		printf ("Child process\n");
		_exit(0);
	}
	else if (pid > 0)
	{
		// parent process
		sleep (2);
		printf ("Parent process\n");
		system ("ps -o pid,ppid,state,tty,comm");
	}
	else 
	{
		printf("Error : fork \n");
	}

	return 0;
}

