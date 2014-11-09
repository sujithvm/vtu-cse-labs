%{
	#include <stdio.h>
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	int valid = 1;
	int nop = 0;
%}

%x OPER
%%
[a-zA-Z0-9]+ { BEGIN OPER; nop++; printf ("Operand : %s\n", yytext); }
<OPER>"+" { if (valid) { valid = 0; a1++; printf ("Operator : %s\n", yytext); } else ext(); }
<OPER>"-" { if (valid) { valid = 0; a2++; printf ("Operator : %s\n", yytext); } else ext(); }
<OPER>"*" { if (valid) { valid = 0; a3++; printf ("Operator : %s\n", yytext); } else ext(); }
<OPER>"/" { if (valid) { valid = 0; a4++; printf ("Operator : %s\n", yytext); } else ext(); }
<OPER>[a-zA-Z0-9]+ { nop++; if (!valid) { valid = 1; printf ("Operand : %s\n", yytext); } else ext(); }
<OPER>. { if (valid) { valid = 0; } else ext(); }
<OPER>"\n" { if (!valid) ext(); else return 0; }
.|\n ext();
%%

int ext()
{
    printf("Invalid expression\n");
    exit(0);
}

int main() 
{
	printf ("Enter expression\n");
	
	yylex();

	printf ("Valid expression\n");
	
	printf ("No of '+' : %d\nNo of '-' : %d\nNo of '*' : %d\nNo of '/' : %d\n", a1, a2, a3, a4);
	
	return 0;
		
}


