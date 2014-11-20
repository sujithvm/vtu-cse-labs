#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct
{
	int name;	// name of process
	int at;		// arrival time
	int burst;	// burst time
	int wait;	// wait time
	int TAT;	// turn around time
	int remaining;	// remaining time
} process;

process p[MAX_PROCESSES];		// shortest job first processes
process p1[MAX_PROCESSES]; 		// round robin processes

int n;			// number of processes in shortest job first
int n1;			// number of processes in round robin

void sjf();		// shortest job first scheduling
void round_robin();	// round robin scheduling

int rtwt = 0;		// round robin - total wait time
int rttat = 0; 		// round robin - total turn around time
int stwt = 0;		// shortest job first - total wait time
int sttat = 0;		// shortest job first - total turn around time

float rawt = 0.0; 	// round robin - average wait time
float ratat = 0.0;	// round robin - average turn around time
float sawt = 0.0;	// shortest job first - average wait time 
float satat = 0;	// shortest job first - average turn around time

int tq, t, i, j, count = 0, temp, sq = 0;

void main()
{
	int ch;
	printf ("\nSelect type of scheduling\n1. SJF\n2. RR\n3. EXIT\n\nEnter your choice: ");
	scanf ("%d",&ch);

	switch(ch)
	{
		case 1:			
			sjf();
			break;
		case 2:
			round_robin();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf ("Invalid choice!!\n");			
	}
}

void sjf()
{
	int tbt = 0, no, k, min;

	printf ("\n\nShortest job first scheduling\n\n");
	printf ("Enter the total number of procedures: ");
	scanf ("%d",&n);

	for (i = 0; i < n; i++)
	{
		printf ("\nProcess : %d\n", (i + 1));
		printf ("Enter procedure name: ");
		scanf ("%d", &p[i].name);

		printf ("Enter arrival time: ");
		scanf ("%d", &p[i].at);

		printf ("Enter burst time of procedure: ");
		scanf ("%d", &p[i].burst);

		p[i].wait = 0;
	}	

	for (i = 0; i < n; i++)
	{
		p[i].remaining = p[i].burst;
		tbt = tbt + p[i].burst;
	}
	
	for (i = 0; i < tbt; i++)
	{
		min = 999;
		for (j = 0; j < n; j++)
		{
			if (p[j].at <= i && p[j].remaining > 0)
			{
				if (p[j].remaining < min)
				{
					min = p[j].remaining;
					no = j;
				}
			}
		}
		
		p[no].remaining = p[no].remaining - 1;

		for (k = 0; k < n; k++)
		{
			if(p[k].at <= i && p[k].remaining > 0 && p[k].name != no) 
			{
				p[k].wait = p[k].wait + 1;
			}
		}
	}

	for (k = 0; k < n; k++)
	{
		p[k].TAT = p[k].burst + p[k].wait;
	}

	printf ("\n\nName\tArrival\tBurst\tWait\tTurn_Around_Time\n");

	for (k = 0; k < n; k++)
	{
		stwt = stwt + p[k].wait;
		sttat = sttat + p[k].TAT;
		printf ("\nP%d\t%d\t%d\t%d\t%d", p[k].name, p[k].at, p[k].burst, p[k].wait, p[k].TAT);
	}
	sawt = (float) stwt / n;
	satat = (float) sttat / n;

	printf ("\n\nTotal wait time = %d\nTotal turn around time = %d\n", stwt, sttat);
	printf ("Average wait time = %f\nAverage turn around time = %f\n", sawt, satat);	
}

void round_robin()
{
	printf ("\n\nRound robin scheduling\n\n");
	printf ("Enter number of processes: ");
	scanf ("%d", &n1);

	printf ("\nEnter burst time for them\n");
	for (i = 0; i < n1; i++)
	{
		scanf ("%d", &p1[i].burst);
		p1[i].remaining = p1[i].burst;
		p1[i].at = 0;
	}

	printf ("Enter time quantum\n");
	scanf ("%d", &tq);
	t = 0;

	while (1)
	{
		for (i = 0, count = 0; i < n1; i++)
		{
			temp = tq;
			if (p1[i].remaining == 0)
			{
				count++;
				continue;
			}

			if (p1[i].remaining > tq)
			{
				p1[i].remaining = p1[i].remaining - tq;				
				t = t + tq;				
			}
			else if (p1[i].remaining >= 0)
			{
				temp = p1[i].remaining;				
				t = t + p1[i].remaining;
				p1[i].remaining = 0;				
			}
			sq = sq + temp;
			p1[i].TAT = sq;
		}
		if (n1 == count)
			break;
	}	

	for (i = 0; i < n1; i++)
	{
		p1[i].wait = p1[i].TAT - p1[i].burst;
		rtwt = rtwt + p1[i].wait;
		rttat = rttat + p1[i].TAT;
	}

	rawt = (float) rtwt/n1;
	ratat = (float) rttat/n1;
	printf ("\n\nProcess\tBurst\tWait\tTurn-Around-Time\n");

	for (i = 0; i < n1; i++)
	{
		printf ("%d\t%d\t%d\t%d\n", i + 1, p1[i].burst, p1[i].wait, p1[i].TAT);
	}

	printf ("\nAverage waiting time = %f\nAverage turn around time = %f\n", rawt, ratat);
}
