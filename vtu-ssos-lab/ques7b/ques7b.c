#include <stdio.h>
#include <stdlib.h>

int main()
{
	char cmd[20];
	int i;
	pid_t pid;
	
	pid = fork();
	if (pid == 0) 
	{
		printf ("Parent process ID = %d\n", getppid());
		printf ("Child process ID = %d\n", getpid());
		gets(cmd);
		system(cmd);
	} 
	else if (pid == -1)
		printf ("Error creating child process\n");
	else 
		wait();

	return 0;	
}
