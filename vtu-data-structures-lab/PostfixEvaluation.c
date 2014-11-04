/***************************************************************************
 *File		: PostfixEvaluation.c
 *Description	: Design, develop, and execute a program in C to evaluate
		  a valid postfix expression using stack.
                  Assume that the postfix expression is read as a single
                  line consisting of non-negative single digit operands 14
                  and binary arithmetic operators. The arithmetic
                  operators are + (add), - (subtract), * (multiply)
		  and / (divide).
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/

#include <stdio.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int op)
{
	stack[++top] = op;
}

int pop()
{
	return stack[top--];
}

int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return 1;
	return 0;
}

int main(void)
{
	char postfix[100];
	int i, l, op1, op2;

	printf("\nEnter postfix expression\n");
	scanf("%s", postfix);

	l = strlen(postfix);

	for (i = 0; i < l; i++)
	{
		if (isOperator(postfix[i]))
		{
			op2 = pop();
			op1 = pop();
			if (postfix[i] == '+')
				push(op1 + op2);
			else if (postfix[i] == '-')
				push(op1 - op2);
			else if (postfix[i] == '*')
				push(op1 * op2);
			else if (postfix[i] == '/')
				push(op1 / op2);
			else if (postfix[i] == '%')
				push(op1 % op2);
		}
		else
			push(postfix[i] - '0');
	}

	printf("\nPostfix Expression = %s\n", postfix);
	printf("\nEvaluation = %d\n", pop());
	return 0;
}

/* Output for infix expression : 1+2*3/4-5%6*7/8+9-1

Enter postfix expression
123*4/+56%7*8/-9+1-

Postfix Expression = 123*4/+56%7*8/-9+1-

Evaluation = 6

*/
