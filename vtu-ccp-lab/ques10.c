#include<stdio.h>
main()
{
    int r1,c1,r2,c2,a[10][10],b[10][10],c[10][10],i,j,k;
    printf("Enter r1,c1,r2,c3\n");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    if(c1!=r2)
        printf("Wrong dimensions\n");
    else
    {
        printf("Enter array A elements\n");
        for(i=0;i<r1;i++)
            for(j=0;j<c1;j++)
                scanf("%d",&a[i][j]);
        printf("Enter array B elements\n");
        for(i=0;i<r2;i++)
            for(j=0;j<c2;j++)
                scanf("%d",&b[i][j]);
        printf("Result \n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                 c[i][j]=0;
                 for(k=0;k<c1;k++)
                     c[i][j]+=a[i][k]*b[k][j];
                 printf("%d ",c[i][j]);
            }
            printf("\n");
        }
        
                     
    }
 
}