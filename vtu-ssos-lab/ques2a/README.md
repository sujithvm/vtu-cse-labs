Problem Statement
=================

Program to recognize a valid arithmetic expression and identify the identifiers and operators present. Print them separately.


### Compilation

```

$ lex ques2a.l 
$ gcc lex.yy.c -ll
$ ./a.out 

```

Output

```
Enter expression
a+4*5-c+d
Operand : a
Operator : +
Operand : 4
Operator : *
Operand : 5
Operator : -
Operand : c
Operator : +
Operand : d
Valid expression
No of '+' : 2
No of '-' : 1
No of '*' : 1
No of '/' : 0

```



