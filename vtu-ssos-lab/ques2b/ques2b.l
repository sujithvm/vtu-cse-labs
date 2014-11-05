%{
	#include <stdio.h>
	int flag = 0;
%}

%%
" and "|" or "|" but " { flag = 1; }
.|\n ;
%%

int main() 
{
	printf ("Enter sentence\n");
	
	yylex();

	if (flag) printf ("Compound sentence\n");
	else printf ("Simple sentence\n");
	
	return 0;
		
}


