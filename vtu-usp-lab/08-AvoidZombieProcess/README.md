Problem Statement
=================

Write a C/C++ program to a avoid a zombie process by forking twice.


### Compilation

```

$ gcc ques8.c
$ ./a.out 
  PID  PPID S TT       COMMAND
 2946  2934 S pts/0    bash
 3641  2946 S pts/0    a.out
 3643  1923 S pts/0    a.out
 3644  3641 S pts/0    sh
 3645  3644 R pts/0    ps

Second forked process. PID = 3643, Parent's PID = 1923


```



