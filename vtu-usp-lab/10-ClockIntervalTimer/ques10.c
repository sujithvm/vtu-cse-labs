#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void system_command(const char *command)
{
	pid_t pid = fork();
	if (pid == 0)
		execl ("/bin/bash", "bash", "-c", command, NULL);
	else
		waitpid (pid, NULL, 0);
}

int main(int argc, char **argv)
{
	int i;
	for (i = 1; i < argc; i++)
	{
		system_command (argv[i]);
		printf ("\n");
	}		

	return 0;
}
