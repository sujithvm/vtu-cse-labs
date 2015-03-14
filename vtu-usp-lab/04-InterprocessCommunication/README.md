Problem Statement
=================

Write a C/C++ program which demonstrates interprocess communication between a reader process and a writer process. Use mkfifo, open, read, write and close APIs in your program.

### Compilation

```

$ gcc read.c -o read.out
$ gcc write.c -o write.out


[Terminal 1]
$ ./write.out test_pipe
Fifo file created...


[Terminal 2]
$ ./read.out test_pipe


[Terminal 1]
Fifo file created...
Enter data to write : 
This is a sample input for inter process communication


[Terminal 2]
Data read from pipe : 
This is a sample input for inter process communication


```



