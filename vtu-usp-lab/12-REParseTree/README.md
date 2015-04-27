Problem Statement
=================

Write a yacc program that accepts a regular expression as input and produce its parse tree as output.


### Compilation

```

$ yacc ques12.y
$ gcc y.tab.c 
$ ./a.out 

Enter regular expression
(a*|b+).(c|d)
Rightmost derivation : 

re => re . re
 => re . (re)
 => re . (re | re)
 => re . (re | d)
 => re . (c | d)
 => (re) . (c | d)
 => (re | re) . (c | d)
 => (re | re+) . (c | d)
 => (re | b+) . (c | d)
 => (re* | b+) . (c | d)
 => (a* | b+) . (c | d)

```



