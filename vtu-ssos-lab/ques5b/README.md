Problem Statement
=================

Program to recognize string 'aaab', 'abbb', 'ab', and 'a' using grammar (a^nb^n, n >= 0)


### Compilation

```

$ lex ques5b.l
$ yacc -d ques5b.y
$ gcc lex.yy.c y.tab.c -ll
$ ./a.out 
Enter string
aaaabbbb
Valid string


```



