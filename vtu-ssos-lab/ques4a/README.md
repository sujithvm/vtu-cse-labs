Problem Statement
=================

Program to recognize a valid arihmetic expression that uses operators +, *, -, * and /.


### Compilation

```

$ lex ques4a.l
$ yacc -d ques4a.y
$ gcc lex.yy.c y.tab.c -ll
$ ./a.out 
Enter the expression
a+b+5
Valid expression
sujith@sujith:~/vtu-cse-labs/vtu-ssos-lab/ques4a$ ./a.out 
Enter the expression
a%
Invalid expression

```



