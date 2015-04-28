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
		putc(str[i], stdout);
}

int main()
{
	int i;

	// generate large strings

	char child_str[STR_LEN];
	for (i = 0; i < STR_LEN; i++) 
		child_str[i] = 'c';
	child_str[STR_LEN - 1] = '\0';

	char parent_str[STR_LEN];
	for (i = 0; i < STR_LEN; i++) 
		parent_str[i] = 'p';
	parent_str[STR_LEN - 1] = '\0';


	// create process

	pid_t pid = fork();

	if (pid == 0) print (child_str);
	else if (pid > 0) print (parent_str);
	else printf("Error : fork \n");
	

	return 0;
}

