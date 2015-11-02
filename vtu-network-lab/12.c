#include<stdio.h>

int min(int x, int y)
{
    if (x < y) return x;
    else return y;
}

int main()
{
    int drop = 0, mini, nsec, cap, count = 0, i, inp[25], process;
    printf("Enter bucket size :");
    scanf("%d", &cap);
    printf("Enter transmission rate :");
    scanf("%d", &process);
    printf("Enter The duration of simulation in seconds : ");
    scanf("%d", &nsec);
    
    for (i = 0; i < nsec; i++)
    {
             printf("Enter packet size at %d sec : ", i + 1);
             scanf("%d", &inp[i]);
    }
    printf("\nSecond|Packet Recieved|Packet Sent|Packet Left|Packet Dropped|\n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < nsec || count != 0; i++)
    {   
        if (i < nsec)
            count += inp[i];

        if (count > cap) 
        {
            drop = count - cap; 
            count = cap; 
        }
        printf("%d", i + 1); 

        if (i < nsec)   printf("\t%d", inp[i]);
        else printf("\t0");

        mini = min(count, process);
        printf("\t\t%d", mini);
        count = count - mini;
        printf("\t\t%d", count);
        printf("\t\t%d\n", drop);
        drop = 0;
        sleep(1);
    }

    return 0;
}
