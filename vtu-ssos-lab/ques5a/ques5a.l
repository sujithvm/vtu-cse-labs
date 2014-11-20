%{
	#include "y.tab.h"	
	extern int yylval;
%}

%%
[a-zA-Z][a-zA-Z0-9]* return ID;
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
. return yytext[0];
\n return 0;
%%
