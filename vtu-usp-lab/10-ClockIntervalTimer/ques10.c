#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define INTERVAL 2

void callme(int signo)
{
	alarm (INTERVAL);
	printf ("Hello world!\n");
}

int main()
{
	struct sigaction action;
	action.sa_handler = callme;
	sigaction (SIGALRM, &action, 0);

	alarm (INTERVAL);

	while (1);

	return 0;
}
