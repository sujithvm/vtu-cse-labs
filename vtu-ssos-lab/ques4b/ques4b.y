%{
	#include <stdio.h>
	#include <stdlib.h>
%}
%token DIGIT ID
%%
var : ID | var ID | var DIGIT;
%%

yyerror()
{
	printf ("Invalid expression\n");
	exit(1);
}

int main()
{
	printf ("Enter the expression\n");
	
	yyparse();

	printf ("Valid input\n");

	return 0;
}
