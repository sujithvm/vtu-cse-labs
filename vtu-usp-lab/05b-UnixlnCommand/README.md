Problem Statement
=================

Write a C/C++ program to emulate the unix ln command.


### Compilation

```
$ touch test_file1
$ ls -l
total 20
-rwxrwxr-x 1 sujith sujith 8614 Mar 14 14:35 a.out
-rw-rw-r-- 1 sujith sujith  342 Mar 14 14:34 ques5b.c
-rw-rw-r-- 1 sujith sujith  139 Mar 14 14:37 README.md
-rw-rw-r-- 1 sujith sujith    0 Mar 14 14:37 test_file1

$ gcc ques5b.c 
$ ./a.out test_file1 test_file2
File test_file2 is linked to file test_file1 

$ ls -l
total 20
-rwxrwxr-x 1 sujith sujith 8614 Mar 14 14:37 a.out
-rw-rw-r-- 1 sujith sujith  342 Mar 14 14:34 ques5b.c
-rw-rw-r-- 1 sujith sujith  139 Mar 14 14:37 README.md
-rw-rw-r-- 2 sujith sujith    0 Mar 14 14:37 test_file1
-rw-rw-r-- 2 sujith sujith    0 Mar 14 14:37 test_file2

```



