#include<stdio.h>
main()
{
    unsigned int n=1;
    int ctr=0;
    while(n!=0)
    {
        n=n<<1;
        ctr++;
    }
    printf("Word length is %d\n",ctr);
}