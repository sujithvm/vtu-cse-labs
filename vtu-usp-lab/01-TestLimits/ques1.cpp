#include <iostream>
#include <unistd.h>

#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

using namespace std;

int main()
{
	cout << "Maximum clock ticks : " << sysconf(_SC_CLK_TCK) << endl;
	cout << "Maximum number of child processes : " << sysconf(_SC_CHILD_MAX) << endl;
	cout << "Maximum path length : " << pathconf("/", _PC_PATH_MAX) << endl;
	cout << "Maximum name length : " << pathconf("/", _PC_NAME_MAX) << endl;
	cout << "Maximum number of opened files : " << sysconf(_SC_OPEN_MAX) << endl;

	return 0;
}

