#include <stdio.h>
typedef struct
{
	int name;
	int at;
	int burst;
	int wait;
	int TAT;
	int remaining;
}process;

process p[5], p1[5];

int n, n1;

void round_robin();
void accept();
void sjf();
int minimum();

int tq, t, i, count = 0, rtwt = 0, rttat = 0, temp, sq = 0, stwt = 0, sttat = 0;
float rawt = 0.0, ratat = 0.0, sawt = 0.0, satat = 0;

void main()
{
	int ch;
	printf("\n1. SJF\n2. RR\n3. EXIT\n\n\tEnter your choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			accept();
			sjf();
			break;
		case 2:
			round_robin();
			break;
		case 3:
			break;
		default:
			printf("Invalid choice!!\n");
	}
}

void accept()
{
	int i;

	printf("Enter the total number of procedures: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter procedure name: ");
		scanf("%d",&p[i].name);

		printf("\nEnter arrival time: ");
		scanf("%d",&p[i].at);

		printf("\nEnter burst time of procedure: ");
		scanf("%d",&p[i].burst);

		p[i].wait = 0;
	}
}

void sjf()
{
	int i, j, tbt = 0, no, k, min;

	for(i=0;i<n;i++)
	{
		p[i].remaining = p[i].burst;
		tbt = tbt + p[i].burst;
	}
	
	for(i=0;i<n;i++)
	{
		min = 999;
		for(j=0;j<n;j++)
		{
			if(p[j].at <= i && p[j].remaining > 0)
			{
				if(p[j].remaining < min)
				{
					min = p[j].remaining;
					no = j;
				}
			}
		}

		printf("%d-p%d-",i,no);
		p[no].remaining = p[no].remaining - 1;

		for(k=0;k<n;k++)
		{
			if(p[k].at <= i && p[k].remaining > 0 && p[k].name != no)
				p[k].wait = p[k].wait + 1;
		}
	}

	printf("%d",i);

	for(k=0;k<n;k++)
	{
		p[k].TAT = p[k].burst + p[k].wait;
	}

	printf("\nName\tArrival\tBurst\tWait\tTurn_Around_Time\n");

	for(k=0;k<n;k++)
	{
		stwt = stwt + p[k].wait;
		sttat = sttat + p[k].TAT;
		printf("\nP%d\t%d\t%d\t%d\t%d", p[k].name, p[k].at, p[k].burst, p[k].wait, p[k].TAT);
	}
	sawt = (float)stwt/n;
	satat = (float)sttat/n;
	printf("\nstwt = %d\tsttat=%d\tsawt=%f\tsatat=%f\n", stwt, sttat, sawt, satat);
}

void round_robin()
{
	printf("Enter number of processes: ");
	scanf("%d",&n1);

	printf("\nEnter burst time for them\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&p1[i].burst);
		p1[i].remaining = p1[i].burst;
		p1[i].at = 0;
	}

	printf("Enter time quantum\n");
	scanf("%d",&tq);
	t = 0;

	while(1)
	{
		for(i=0,count=0;i<n1;i++)
		{
			temp = tq;
			if(p1[i].remaining == 0)
			{
				count++;
				continue;
			}

			if(p1[i].remaining > tq)
			{
				p1[i].remaining = p1[i].remaining - tq;
				printf("%d-",t);
				t = t + tq;
				printf("P%d-",i);
			}
			else
				if(p1[i].remaining >= 0)
				{
					temp = p1[i].remaining;
					printf("%d-",t);
					t = t + p1[i].remaining;
					printf("P%d-",i);
				}
			sq = sq + temp;
			p1[i].TAT = sq;
		}
		if(n1 == count)
			break;
	}
	printf("%d",t);

	for(i=0;i<n1;i++)
	{
		p1[i].wait = p1[i].TAT - p1[i].burst;
		rtwt = rtwt + p1[i].wait;
		rttat = rttat + p1[i].TAT;
	}
	rawt = (float)rtwt/n1;
	ratat = (float)rttat/n1;
	printf("\nProcess_no\tBurst_time\tWait_time\tTurn_Around_Time\n");

	for(i=0;i<n1;i++)
	{
		printf("%d\t%d\t%d\t%d\n",i+1,p1[i].burst,p1[i].wait,p1[i].TAT);
	}

	printf("rawt = %f\tratat = %f\n", rawt, ratat);
}
