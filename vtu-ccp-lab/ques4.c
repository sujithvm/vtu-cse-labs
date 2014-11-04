#include<stdio.h>
main()
{
    int arr[100];
    int n,i,sum,x;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter %d coefficients\n",(n+1));
    for(i=0;i<=n;i++)
         scanf("%d",&arr[i]);
    printf("Enter x\n");
    scanf("%d",&x);
    sum=arr[n]*x;
    
    for(i=n-1;i>=1;i--)
        sum=(sum+arr[i])*x;
    sum+=arr[0];
    printf("Sum of term = %d\n",sum);
}