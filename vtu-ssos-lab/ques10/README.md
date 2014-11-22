Problem Statement
=================

Design, develop and execute a program in C/C++ to simulate the working of Shortest Remaining Time and Round-Robin
Scheduling Algorithms. Experiment different quantum sizes for the Round-Robin algorithm.
In all cases, determing the average turn around time. The input can be read from keyboard or from a file.

### Compilation

```

$ gcc ques10.c
$ ./a.out 

Select type of scheduling
1. SJF
2. RR
3. EXIT

Enter your choice: 1


Shortest job first scheduling

Enter the total number of procedures: 4

Process : 1
Enter procedure name: 0
Enter arrival time: 0
Enter burst time of procedure: 8

Process : 2
Enter procedure name: 1
Enter arrival time: 1
Enter burst time of procedure: 4

Process : 3
Enter procedure name: 2
Enter arrival time: 2
Enter burst time of procedure: 9

Process : 4
Enter procedure name: 3
Enter arrival time: 3
Enter burst time of procedure: 5


Name	Arrival	Burst	Wait	Turn_Around_Time

P0	0	8	9	17
P1	1	4	0	4
P2	2	9	15	24
P3	3	5	2	7

Total wait time = 26
Total turn around time = 52
Average wait time = 6.500000
Average turn around time = 13.000000

```

Run #2

```

Select type of scheduling
1. SJF
2. RR
3. EXIT

Enter your choice: 2


Round robin scheduling

Enter number of processes: 3

Enter burst time for them
24
3
3
Enter time quantum
4


Process	Burst	Wait	Turn-Around-Time
1	24	6	30
2	3	4	7
3	3	7	10


Total wait time = 17
Total turn around time = 47
Average waiting time = 5.666667
Average turn around time = 15.666667


```



