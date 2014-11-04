#include<stdio.h>
main()
{
    int n,arr[100],i,j,temp;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
    printf("Elements before sorting\n");
    for(i=0;i<n;i++)
       printf("%d\n",arr[i]);
    for(i=0;i<n-1;i++)
    {
         for(j=0;j<n-1-i;j++)
         {
              if(arr[j]>arr[j+1])
              {
                   temp=arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;
              }
         }
     }
     printf("Elements after sorting \n");
     for(i=0;i<n;i++)
       printf("%d\n",arr[i]);

}