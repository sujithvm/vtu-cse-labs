/***************************************************************************
 *File		: String.cpp
 *Description	: Design, develop, and execute a program in C++ to 
		  create a class called STRING and implement the following 
		  operations. Display the results after every operation 
		  by overloading the operator <<. 
		  i. STRING s1 = “VTU” 
		  ii. STRING s2 = “BELGAUM” 
 		  iii. STIRNG s3 = s1 + s2; (Use copy constructor) 
		  	
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 4 November 2013
***************************************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class STRING
{
	private :
 		char *str;
	public :
		STRING();
		STRING(char *s);
		STRING(const STRING &sobj);
                STRING operator + (STRING &str);
                friend ostream & operator <<(ostream &ptr, STRING &obj);
};

STRING :: STRING()
{
        str = NULL;
}

STRING :: STRING(char *s)
{
	int len = strlen(s);
        str = (char *) malloc ((len + 1) * sizeof(char));
        strcpy(str, s);
}

STRING :: STRING(const STRING &sobj)
{
	int len = strlen(sobj.str);
        str = (char *) malloc ((len + 1) * sizeof(char));
        strcpy(str, sobj.str);
}

STRING STRING :: operator + (STRING &s2)
{
        STRING temp;
	int len1 = strlen(str);
	int len2 = strlen(s2.str);
        
        temp.str = (char *) malloc ((len1 + len2 + 1) * sizeof(char));

        strcpy(temp.str, str);
        strcat(temp.str, s2.str);

        return temp;
}

ostream & operator << (ostream &ptr, STRING &obj)
{
        ptr << obj.str << endl;
        return ptr;
}

int main(void)
{
	cout << "String Test \n" << endl;
        STRING s1 = "VTU";
        STRING s2 = "BELGAUM";
        STRING s3 = s1 + s2;

        cout << "s1 = " << s1 << endl;
        cout << "s2 = " << s2 << endl;
        cout << "s3 = " << s3 << endl;

        return 0;
}

/*

String Test

s1 = VTU

s2 = BELGAUM

s3 = VTUBELGAUM

*/