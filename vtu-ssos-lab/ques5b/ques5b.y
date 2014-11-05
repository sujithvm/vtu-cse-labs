%{
	#include <stdio.h>
	#include <stdlib.h>	
%}

%token A B
%%
S : A S B
  | ;
%%

yyerror() 
{
	printf ("Invalid input\n");
	exit(1);
}

int main()
{
	printf ("Enter string\n");
	
	yyparse();

	printf ("Valid string\n");	

	return 0;
}
