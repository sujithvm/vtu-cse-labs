Problem Statement
=================

Write a C program to implement the syntax-directed definition of "if E then S1" and "if E then S1 else S2"


### Compilation

```

$ gcc ques11.c 
$ ./a.out 
Format of if stmt 
For example
1) if (a < b) then (s = a); 
2) if (a < b) then (s = a) else (s = b); 

Enter stmt:
if (a < b) then (s = a) else (s = b);
if (a < b) goto 101 
goto 102 
101 : (s = a)
goto 103 
102 : (s = b) 
103 : STOP 


```



