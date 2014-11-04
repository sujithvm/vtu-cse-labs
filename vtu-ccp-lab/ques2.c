#include<stdio.h>
main()
{
   int gcd,lcm,n1,n2,num1,num2,r;
   printf("Enter n1 and n2 \n");
   scanf("%d%d",&n1,&n2);
   num1=n1;
   num2=n2;
   while(n1%n2!=0)
   {
      r=n1%n2;
      n1=n2;
      n2=r;
   }
   gcd=n2;
   lcm=(num1*num2)/gcd;
   printf("GCD and LCM of %d and %d are %d and %d respectively\n",num1,num2,gcd,lcm);
   
}