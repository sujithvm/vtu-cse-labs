%{
	#include <stdio.h>
	int comment_count = 0;
%}

%s COMMENT
%%
"//".* { comment_count++; }
"/*".*"*/" { comment_count++; }
"/*" { BEGIN COMMENT; comment_count++; }
<COMMENT>. ;
<COMMENT>\n ;
<COMMENT>"*/" { BEGIN 0; }
%%

int main (int argc, char **argv) 
{
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	yylex();
	
	printf ("Comment count = %d\n",  comment_count);			
	
	return 0;
		
}


