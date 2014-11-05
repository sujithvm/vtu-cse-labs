Problem Statement
=================

Using OpenMP, Design, Develop and run a multi threaded program to generate and print fibonacci series.
One thread has to generate the number upto the specified limit and another thread has to print them.
Ensure proper synchronization.

### Compilation

```
$ gcc ques11.c -fopenmp
$ ./a.out 
Enter n
10
Computation thread id = 1,	fib num = 3
Computation thread id = 1,	fib num = 4
Computation thread id = 1,	fib num = 5
Computation thread id = 1,	fib num = 6
Computation thread id = 1,	fib num = 7
Computation thread id = 1,	fib num = 8
Computation thread id = 1,	fib num = 9
Computation thread id = 1,	fib num = 10

Fibonacci Series
Fibonacci series : 0 - thread id, Fib num = 0 
0 - thread id, Fib num = 1 
0 - thread id, Fib num = 1 
0 - thread id, Fib num = 2 
0 - thread id, Fib num = 3 
0 - thread id, Fib num = 5 
0 - thread id, Fib num = 8 
0 - thread id, Fib num = 13 
0 - thread id, Fib num = 21 
0 - thread id, Fib num = 34 



```



