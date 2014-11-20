Problem Statement
=================

Program to evaluate an arithmetic expression invoking operators +, -, * and / .


### Compilation

```

$ lex ques5a.l
$ yacc -d ques5a.y 
$ gcc lex.yy.c y.tab.c -ll
$ ./a.out 

```

Run #1

```

Enter expression
2+3*10-16/2
Result : 24

Valid expression

```

Run #2

```

Enter expression
-2*4
Result : -8

Valid expression

```

Run #3

```

Enter expression
32+
syntax error
Invalid expression

```

Run #4

```

Enter expression
*100
syntax error
Invalid expression

```
