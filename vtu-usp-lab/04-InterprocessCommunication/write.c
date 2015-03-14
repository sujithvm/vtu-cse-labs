#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
	int pipe;
	char buf[BUF_SIZE];

	if (argc != 2)
	{
		printf ("usage : %s <file> \n", argv[0]);
		exit(0);
	}

	if (access(argv[1], F_OK) == -1) 
	{
		if (mkfifo(argv[1], 0777) != -1)		
		{	
			printf ("Fifo file created...\n");			
		}		
		else 
		{
			printf ("Error : create fifo file \n");
			exit(1);
		}		
	}
	
	pipe = open(argv[1], O_WRONLY);
	if (pipe != -1)
	{
		printf ("Enter data to write : \n");
		gets(buf);
		
		write(pipe, buf, sizeof(buf));
		close(pipe); 
	}

	return 0;
 }
