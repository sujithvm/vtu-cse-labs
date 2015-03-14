Problem Statement
=================

Consider the last 100 bytes as a region. Write a C/C++ program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked. If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.


### Compilation

```

$ g++ ques3.cpp 
$ ./a.out test_file

Setting lock...

File locked...

Last 50 bytes read from file : 
 guardian, a watchful protector, a Dark Knight.


Releasing lock...

File unlocked...


```



