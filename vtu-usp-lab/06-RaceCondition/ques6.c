#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STR_LEN 100

static void print(const char *str)
{
	int i;

	setbuf(stdout, NULL);

	for (i = 0; i < strlen(str); i++) 
	{
		putc(str[i], stdout);
	
		int delay = 100000000;
		while (delay--);
	}
}

int main()
{
	pid_t pid = fork();

	if (pid == 0) print ("child");
	else if (pid > 0) print ("parent");
	else printf("Error : fork \n");
	

	return 0;
}

