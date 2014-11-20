%{
	#include <stdio.h>
	#include <stdlib.h>	
%}

%token NUMBER ID
%left '+''-'
%left '*''/'
%nonassoc UMINUS
%%
Start : ID'='exp|exp { printf ("Result : %d\n", $1); }
exp : exp'+'exp { $$ = $1 + $3; }
    | exp'-'exp { $$ = $1 - $3; }
    | exp'*'exp { $$ = $1 * $3; }
    | exp'/'exp { if ($3 == 0) yyerror("Divide by zero error"); else $$ = $1 / $3; }
    | '('exp')' { $$ = $2; }
    | NUMBER { $$ = $1; }
    |'-'exp %prec UMINUS { $$ = -$2; }
    ;
%%

yyerror(char *s) 
{
	printf ("%s\n", s);
	printf ("Invalid expression\n");
	exit(1);
}

int main()
{
	printf ("Enter expression\n");
	
	yyparse();

	printf ("\nValid expression\n");		

	return 0;
}
