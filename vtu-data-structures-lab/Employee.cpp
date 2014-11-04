
/***************************************************************************
*File		: Employee.cpp
*Description	: Program to read data of n number of employees, calculate their
  		  net salary and print the details.
*Author		: Sujith V
*Compiler	: MinGW (GCC) compiler, Windows 8
*Date		: 3 November 2013
***************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

class EMPLOYEE
{
	private:
		int empNumber;
		char empName [30];
		int basicSal, allAllowances, incomeTax, netSal;
	public:
		void fnReadData();
		void fnCalcSal();
		void fnDisplay();
};

void EMPLOYEE :: fnReadData()
{
	cout << "\nEnter Name" << endl;
	cin >> empName;
	cout << "Enter Employee Number" << endl;
	cin >> empNumber;
	cout << "Enter Basic" << endl;
	cin >> basicSal;	
}

void EMPLOYEE :: fnCalcSal()
{
	int iGSal;
	allAllowances = (23 * basicSal) / 100;
	iGSal = basicSal - allAllowances;
	incomeTax = (30 * iGSal) / 100;
	netSal = basicSal + allAllowances - incomeTax;	
}

void EMPLOYEE :: fnDisplay()
{
	printf ("%10s %10d %10d %10d %10d %10d\n", empName, empNumber, basicSal, allAllowances, incomeTax, netSal);
}

int main(void)
{
	int n;
	cout << "Enter the number of Employees\n";
	cin >> n;
	EMPLOYEE emp [100];
	cout << "Enter the details of employees\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter employee "<< (i + 1) << " details " << endl; 
		emp[i].fnReadData();
		emp[i].fnCalcSal();
	}
	cout << "\nAll details : " << endl;
	printf ("\n%10s %10s %10s %10s %10s %10s\n", "Name", "Number", "BasicSal", "Allowance", "IncomeTax", "NetSalary");
	
	for (int i = 0; i < n; i++)
		emp[i].fnDisplay();

	return 0;
}

/* Output :

Enter the number of Employees
3
Enter the details of employees

Enter employee 1 details

Enter Name
alpha
Enter Employee Number
243
Enter Basic
1000000

Enter employee 2 details

Enter Name
beta
Enter Employee Number
499
Enter Basic
200000

Enter employee 3 details

Enter Name
gamma
Enter Employee Number
937
Enter Basic
300000

All details :

      Name     Number   BasicSal  Allowance  IncomeTax  NetSalary
     alpha        243    1000000     230000     231000     999000
      beta        499     200000      46000      46200     199800
     gamma        937     300000      69000      69300     299700

*/

