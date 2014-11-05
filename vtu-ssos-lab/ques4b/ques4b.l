%{
	#include "y.tab.h"
%}
%%
[a-zA-Z]+ { return ID; }
[0-9]+ { return DIGIT; }
. { return yytext[0]; }
\n { return 0; }
%%
