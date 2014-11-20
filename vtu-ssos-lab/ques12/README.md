Problem Statement
=================

Design, develop and run a program to implement the Banker's Algorithm. Demonstrate its working with different data values.

### Compilation

```

$ gcc ques12.c
$ ./a.out 


Bankers algorithm

Enter the number of processes
5
Enter the number of resources
4
Enter the claim matrix
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Enter the allocation matrix
0 0 1 2
1 0 0 0
1 3 5 4 
0 6 3 2
0 0 1 4
Enter total number of instances of each resource
3 14 12 12

Claim matrix		Allocation matrix	Need matrix
0 0 1 2 		0 0 1 2 		0 0 0 0 
1 7 5 0 		1 0 0 0 		0 7 5 0 
2 3 5 6 		1 3 5 4 		1 0 0 2 
0 6 5 2 		0 6 3 2 		0 0 2 0 
0 6 5 6 		0 0 1 4 		0 6 4 2 

The system is in safe state
Safe sequence : 0 2 3 4 1 


```



