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

	if ((pipe = open(argv[1], O_RDWR)) != -1) 
	{
		if (read(pipe, buf, sizeof(buf)) != -1)
		{
			printf ("Data read from pipe : \n");
			printf ("%s\n", buf);
		}
		else 
		{
			printf ("Error : read \n");
		}
		close (pipe);
	}
	else 
	{
		printf ("Error : open \n");
	}

	return 0;
 }
