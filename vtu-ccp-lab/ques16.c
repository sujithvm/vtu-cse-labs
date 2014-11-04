#include<stdio.h>
#include<string.h>
int matchany(char a[],char b[])
{
    int l1,i,l2,j;
    l1=strlen(a);
    l2=strlen(b);
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
            if(a[i]==b[j])
                return j+1;
    return -1;
    
}
main()
{
     char a[1000],b[1000];
     printf("Enter two strings\n");
     gets(a);
     gets(b);
     int p=matchany(a,b);
     if(p==-1)
         printf("No match\n");
     else
         printf("Match = %d\n",p);
}