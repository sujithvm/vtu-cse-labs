#include<stdio.h>
int isprime(int x)
{
    int i=0;
    for(i=2;i<=x/2;i++)
        if(x%i==0)
           return i;
    return 0;
}
main()
{
    int n;
    printf("Enter num\n");
    scanf("%d",&n);
    if(isprime(n))
      printf("%d is not prime\n",n);
    else
      printf("%d is prime\n",n);
}