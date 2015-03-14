#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i;
	char **ptr;
	extern char **environ;

	for (ptr = environ; *ptr != NULL; ptr++)
		printf("%s\n", *ptr);

	return 0;
}
