/***************************************************************************
 *File		: Date.cpp
 *Description	: Design, develop, and execute a program in C++ to create a class 
		  called DATE with methods to accept two valid dates in the form 
		  dd/mm/yy and to implement the following operations by 
		  overloading the operators + and -. After every operation 
		  the results are to be displayed by overloading the operator <<. 
		  i. no_of_days = d1 – d2; where d1 and d2 are DATE objects, 
		     d1 >=d2 and no_of_days is an integer. 
		  ii. d2 = d1 + no_of_days; where d1 is a DATE object and 	
		     no_of_days is an integer. 
		  	
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 4 November 2013
***************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

class DATE
{
	private :
		int mon, day, year, month [13];
	public:
		DATE();
		void read();
		int operator - (DATE d2);
		DATE operator + (int num);
		friend ostream & operator << (ostream &ptr, DATE &obj);		
};

DATE :: DATE()
{
	month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
	month[4] = month[6] = month[9] = month[11] = 30;
	month[2] = 28;
}

void DATE :: read()
{
	cout << "Enter date in (dd/mm/yyyy) format " << endl;
	scanf("%d/%d/%d", &day, &mon, &year);
}

int DATE :: operator - (DATE d2)
{
	int nod = 0;
	if (year < d2.year || (year == d2.year && mon < d2.mon) || (year == d2.year && mon == d2.mon && day < d2.day))
		cout << "Subtraction not possible\n";
	else
	{
		while ((year!=d2.year) || (mon!=d2.mon) || (day!=d2.day))
		{
			nod ++;
			d2.day ++;
			if ((d2.year % 4 == 0 && d2.mon == 2)? d2.day> 29 : d2.day > month[d2.mon])
			{
				d2.day = 1;
				d2.mon++;
			}
			if(d2.mon>12)
			{
				d2.mon = 1;
				d2.year++;
			}
		}		
	}
	return nod;
}

DATE DATE::operator + (int num)
{
	while(num!=0)
	{
		num--;
		day ++;
		if ((year % 4 == 0 && mon == 2) ? day>29 : day > month[mon])
		{
			day = 1;
			mon++;
		}
		if (mon > 12)
		{
			mon = 1;
			year++;
		}
	}
	return *this;
}

ostream &operator << (ostream& ptr, DATE &obj)
{
	ptr << "Date : " << obj.day << "/" << obj.mon << "/" << obj.year;
	return ptr;
}

int main(void)
{
	cout << "Date Test " << endl;
	DATE d1, d2; int no;

	cout << "\nEnter the first date " << endl ;
	d1.read(); 
	cout << "\nEnter the second date" << endl;
	d2.read();

	no = d1 - d2;
	cout << "\nNumber of days = " << no << endl;
	cout << "\nEnter number of days to add to date 2" << endl;
	cin >> no;
	d1 = d2 + no;

	cout << "New Date after adding days:\n" << d1 << endl;
	return 0;
}

/*

Date Test

Enter the first date
Enter date in (dd/mm/yyyy) format
4/11/2013

Enter the second date
Enter date in (dd/mm/yyyy) format
24/6/2013

Number of days = 133

Enter number of days to add to date 2
133
New Date after adding days:
Date : 4/11/2013

*/
