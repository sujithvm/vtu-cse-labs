%{
	#include <stdio.h>
	int char_count = 0, word_count = 0, line_count = 0, space_count = 0;
%}

%%
[ ] { space_count++;  char_count++; }
[\n] { line_count++; char_count++; }
[\t] { space_count += 4; char_count++; }
[^ \t\n]+ { word_count++; char_count += yyleng; }
. { char_count++; }
%%

int main (int argc, char **argv) 
{
	FILE *fp = fopen(argv[1],"r");

	if (!fp) 
	{
		printf ("Error in arguments");
		exit(1);
	}
	yyin = fp;
	yylex();
	
	printf ("Character count = %d \nWord count = %d \nLine count = %d \nSpace count = %d \n", 
			char_count, word_count, line_count, space_count);
	
	return 0;
		
}


