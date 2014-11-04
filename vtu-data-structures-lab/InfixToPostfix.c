/***************************************************************************
 *File	    	: InfixToPostfix.c
 *Description   : Design, develop and execute a program in C to convert
		  a given valid parenthesized infix arithmetic expression
		  to postfix expression and pint both expressions.
		  The expression consists of single character operands
		  and binary operators + (plus), - (minus),
		  * (multiply) and / (divide)
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/

#include <stdio.h>

char infix[100];
char postfix[100];
int top;
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

typedef enum
{
	lparen, rparen, plus, minus, divide, times, mod, eos, operand
} precedence;

precedence stack[20];

precedence getToken(char *symbol, int *n)
{
	*symbol = infix[(*n)++];
	switch(*symbol)
	{
		case '('  : return lparen;
		case ')'  : return rparen;
		case '+'  : return plus;
		case '-'  : return minus;
		case '/'  : return divide;
		case '*'  : return times;
		case '%'  : return mod;
		case '\0' : return eos;
		default   : return operand;
	}
}

precedence pop()
{
	return stack[top--];
}

void push(precedence ele)
{
	stack[++top] = ele;
}

char printToken(precedence token)
{
	switch(token)
	{
		case lparen : return '(';
		case rparen : return ')';
		case plus   : return '+';
		case minus  : return '-';
		case divide : return '/';
		case times  : return '*';
		case mod    : return '%';
		case eos    : return ' ';
	}
}

void infixToPostfix(char infix[])
{
	char symbol;
	precedence token;
	int n = 0, j = 0;
	top = 0;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token!=eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
			postfix[j++] = symbol;
		else if (token == rparen)
		{
			while (stack[top] != lparen)
				postfix[j++] = printToken(pop());
			pop();
		}
		else
		{
			while (isp[stack[top]] >= icp[token])
				postfix[j++] = printToken(pop());
			push(token);
		}
	}
	while ((token = pop()) != eos)
		postfix[j++] = printToken(token);
	postfix[j] = '\0';
}

int main (void)
{
	printf("Enter the infix expression\n");
	scanf("%s", infix);

	infixToPostfix(infix);

	printf("\nInfix expression : %s\n", infix);
	printf("\nPostfix expression : %s\n", postfix);

	return 0;
}

/* Output :

Enter the infix expression
1+2*3/4-5%6*7/8+9-1

Infix expression : 1+2*3/4-5%6*7/8+9-1

Postfix expression : 123*4/+56%7*8/-9+1-

*/

