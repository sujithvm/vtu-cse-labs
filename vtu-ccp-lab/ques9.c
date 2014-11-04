#include<stdio.h>
#include<float.h>
#include<math.h>
main()
{
    int i=1;
    float term=1,sum=1,x,e;
    printf("Enter x\n");
    scanf("%f",&x);
    while(term>FLT_EPSILON)
    {
        term=term*x/i;
        sum+=term;
        i++;
    }
    e=exp(x);
    printf("Taylor series sum %f\n",sum);
    printf("Exp function %f\n",sum);
}