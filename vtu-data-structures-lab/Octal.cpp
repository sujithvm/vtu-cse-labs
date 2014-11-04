#include <iostream>
#include <math.h>

using namespace std;

class OCTAL
{
	private :
		int num;
	public :
		OCTAL(int x);	
		int decimalToOctal(int dec);
		int octalToDecimal(int oct);
		int operator + (int k);
		friend ostream & operator <<(ostream &ptr, OCTAL &obj);
};

OCTAL :: OCTAL(int x)
{
	num = decimalToOctal(x);
}

int OCTAL :: decimalToOctal(int dec)
{
	int n = 0, t = 1;
	while (dec != 0)
	{
		n += (dec % 8) * t;
		t *= 10;
		dec /= 8;
	}
	return n;
}

int OCTAL :: octalToDecimal(int oct)
{
	int n = 0, t = 1;
	while (oct != 0)
	{
		n += (oct % 10) * t;
		t *= 8;
		oct /= 10;
	}
	return n;
}

int OCTAL :: operator + (int k)
{
	return octalToDecimal(num) + k;
}

ostream & operator <<(ostream &ptr,OCTAL &obj)
{
        ptr << "Octal Equivalent : " << obj.num << endl;
	ptr << "Decimal Equivalent : " << obj.octalToDecimal(obj.num) << endl; 
}

int main(void)
{
	cout << "Octal Test" << endl;

	int x, k;
	cout << "\nEnter element x for \"OCTAL h = x \"" << endl;
	cin >> x;

	OCTAL h = x;
		
	cout << "\nEnter element k to add for \"int y = h + k\"" << endl;
	cin >> k;

	int y = h + k;
	
	cout << "\nh values :\n" << h;

	cout << "\ny values : " << endl;
	cout << "Octal Equivalent : " << h.decimalToOctal(y) << endl;
	cout << "Decimal Equivalent : " << y << endl; 

	return 0;
}

/*

Octal Test

Enter element x for "OCTAL h = x "
24

Enter element k to add for "int y = h + k"
63

h values :
Octal Equivalent : 30
Decimal Equivalent : 24

y values :
Octal Equivalent : 127
Decimal Equivalent : 87

*/



