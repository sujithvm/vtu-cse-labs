#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STR_LEN 100

static void print(char *str)
{
        char *ptr;
        int c;

        setbuf(stdout, NULL);

        for (ptr = str; (c = *ptr++) != '\0'; )
                putc(c, stdout);
}

int main()
{
	int i;

	// generate large strings

	char child_str[STR_LEN];
	for (i = 0; i < STR_LEN; i++) 
		child_str[i] = 'c';
	child_str[STR_LEN] = '\0';

	char parent_str[STR_LEN];
	for (i = 0; i < STR_LEN; i++) 
		parent_str[i] = 'p';
	parent_str[STR_LEN] = '\0';


	// create process

        pid_t pid = fork();

        if (pid == 0) 
	{
		// child process
		print (child_str);
	}
	else if (pid > 0)
	{
		// parent process
		print (parent_str);
	}
	else 
	{
		printf("Error : fork \n");
	}

	return 0;
}

