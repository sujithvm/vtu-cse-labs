#include<stdio.h>
#include<omp.h>
main()
{
    int a[100],b[100],c[100];
    int n,i;
    omp_set_num_threads(5);
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter elements of array1\n");
    for(i=0;i<n;i++)
         scanf("%d",&a[i]);
    printf("Enter elements of array2\n");
    for(i=0;i<n;i++)
         scanf("%d",&b[i]);
   
    #pragma omp parallel for shared(c) private(i)
    for(i=0;i<n;i++)
    {
         c[i]=a[i]+b[i];
         printf("Thread %d \n",omp_get_thread_num());
    }

    printf("Result\n");
    for(i=0;i<n;i++)
         printf("%d\n",c[i]);
}