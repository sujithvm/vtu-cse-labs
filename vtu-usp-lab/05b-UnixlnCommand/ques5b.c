#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage : %s <file1> <file2>\n", argv[0]);
		return 0;
	}

	if (link(argv[1], argv[2]) != -1)
	{
		printf ("File %s is linked to file %s \n", argv[2], argv[1]); 
	}
	else 
	{
		printf("Error : link \n");
	}

	return 0;
}
