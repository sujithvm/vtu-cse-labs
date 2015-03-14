Problem Statement
=================

Write a C/C++ program that creates a zombie and then calls system to execute the ps command to verify that the process is zombie.


### Compilation

```

$ gcc ques7.c
$ ./a.out 
Child process
Parent process
  PID  PPID S TT       COMMAND
 2995  2986 S pts/0    bash
 4190  2995 S pts/0    a.out
 4191  4190 Z pts/0    a.out <defunct>
 4192  4190 S pts/0    sh
 4193  4192 R pts/0    ps
```



