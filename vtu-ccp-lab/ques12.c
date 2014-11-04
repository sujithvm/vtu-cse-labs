#include<stdio.h>
unsigned int rightrot(unsigned int x,int n);
main()
{
    unsigned int x;
    int n;
    printf("Enter x\n");
    scanf("%u",&x);
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Value after rotating is %u\n",rightrot(x,n));
}
unsigned int rightrot(unsigned int x,int n)
{
    int i=0;
    unsigned int max=1;
    max=max<<31;
    for(i=0;i<n;i++)
    {
        if(x%2==0)
           x=x>>1;
        else
        {
           x=x>>1;
           x=x+max;
        }
    }
    return x;
}

