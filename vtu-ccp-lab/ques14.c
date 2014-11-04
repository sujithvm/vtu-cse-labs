#include<stdio.h>
#include<omp.h>
#include<math.h>
main()
{
    int n,i,j;
    int arr[1000]={0};
    printf("Enter n\n");
    scanf("%d",&n);
    
    for(i=2;i<=sqrt(n);i++)
    {
         if(arr[i]==0)
         {
              #pragma omp parallel for 
              for(j=i*i;j<=n;j=j+i)
                  arr[j]=1;
         }
         
    }
    
    for(i=2;i<=n;i++)
         if(arr[i]==0)
              printf("%d\n",i);
   
}
