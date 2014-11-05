Problem Statement
=================

Program to recognize a valid variable, which starts with a letter followed by any number of letters or digits.


### Compilation

```

$ lex ques4b.l
$ yacc -d ques4b.y
$ gcc lex.yy.c y.tab.c -ll
$ ./a.out 
Enter the expression
abc5
Valid input
$ ./a.out 
Enter the expression
5abc
Invalid expression


```



