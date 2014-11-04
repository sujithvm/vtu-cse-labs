#include<stdio.h>
main()
{
    int arr[100];
    int n,ele,start,end,flag=0,i,mid;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter element to search for \n");
    scanf("%d",&ele);
    start=0;
    end=n-1;
    mid=(start+end)/2;
    while(arr[mid]!=ele)
    {
         if(start==end)
         {
              flag=1;
              break;
         }
         if(arr[mid]>ele)
            end=mid-1;
         if(arr[mid]<ele)
            start=mid+1;
         mid=(start+end)/2; 
    }
    if(flag==1)
        printf("Element not found\n");
    else
        printf("Element found at %d position\n",(mid+1));
}