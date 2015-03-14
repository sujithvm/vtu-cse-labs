#include <iostream>
#include <unistd.h>

#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

using namespace std;

int main()
{
	#ifdef _POSIX_JOB_CONTROL
		cout << "POSIX job control support : true" << endl;
	#else
		cout << "POSIX job control support : false" << endl;
	#endif


	#ifdef _POSIX_SAVED_IDS
		cout << "Saved set UID and GID support : true" << endl;
	#else
		cout << "Saved set UID and GID support : false" << endl;
	#endif


	#ifdef _POSIX_CHOWN_RESTRICTED
		cout << "CHOWN restriction : true" << endl;
	#else
		cout << "CHOWN restriction : false" << endl;
	#endif


	#ifdef _POSIX_NO_TRUNC
		cout << "Truncation : true " << endl;
	#else
		cout << "Truncation : false " << endl;
	#endif


	#ifdef _POSIX_VDISABLE
		cout << "Disable special characters for terminal files : true " << endl;
	#else
		cout << "Disable special characters for terminal files : false " << endl;
	#endif


	return 0;
}

