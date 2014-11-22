#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	if ((pid = fork()) < 0) 
	{
		printf ("Error\n");
		exit(1);
	}
	if (pid == 0) 
	{
		printf ("Child process\n");
		printf ("My id = %d, parent id = %d\n", getpid(), getppid());
	}
	else 
	{
		printf ("Parent process\n");
		printf ("My id = %d, child id = %d\n", getpid(), pid);
		wait();
	}	

	return 0;
}
