#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 256

using namespace std;


int main(int argc, char **argv)
{
	int fd;
	char buf[BUF_SIZE];
	struct flock fvar;

	if (argc != 2)
	{
		cout << "usage : " << argv[0] << " <file> " << endl;
		exit(0);
	}

	if ((fd = open(argv[1], O_RDWR)) == -1)
	{
		cout << "Error : file open " << endl;
		exit(1);
	}

	fvar.l_type = F_WRLCK;
	fvar.l_whence = SEEK_END;
	fvar.l_start = SEEK_END - 100;
	fvar.l_len = 100;
	
	cout << "\nSetting lock..." << endl;
	
	if ((fcntl(fd, F_SETLK, &fvar)) == -1)
	{     
		fcntl(fd, F_GETLK, &fvar);
		cout << "Error : File already locked by process with pid  : " << fvar.l_pid << endl;	
		exit(1);	
	}

	cout << "\nFile locked..." << endl;

	if ((lseek(fd, SEEK_END - 50, SEEK_END)) == -1)
	{
		cout << "Error : lseek " << endl;
		exit(1);
	}

	if ((read(fd, buf, 50)) == -1)
	{
		cout << "Error : read " << endl;
		exit(1);
	}

	cout << "\nLast 50 bytes read from file : " << endl;
	cout << buf << endl;

	cout << "\nReleasing lock..." << endl;
	
	fvar.l_type = F_UNLCK;
	fvar.l_whence = SEEK_SET;
	fvar.l_start = 0;
	fvar.l_len = 0;

	if ((fcntl(fd, F_UNLCK, &fvar)) == -1)
	{
		cout << "Error : unlock " << endl;
		exit(1);
	}

	cout << "\nFile unlocked..." << endl;

	close(fd);

	return 0;
 }
