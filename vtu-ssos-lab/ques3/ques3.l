%{
	#include <stdio.h>
	int count = 0;
%}

ID [a-zA-Z][a-zA-Z0-9]*
%s DEFN
%%
[ \t] ;
"int "|"char "|"float "|"double " { BEGIN DEFN; }
<DEFN>{ID}"," { count++; printf ("%s\n", yytext); }
<DEFN>{ID}";" { count++; BEGIN 0; printf ("%s\n", yytext); }
.|\n ;
%%

int main(int argc, char **argv) 
{
	yyin = fopen(argv[1], "r");

	yylex();

	printf ("\nNumber of identifiers : %d\n", count);
	
	return 0;		
}


