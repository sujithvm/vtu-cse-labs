#include<stdio.h>
#include<math.h>
main()
{
   float r1,r2,im;
   int a,b,c,disc;
   printf("Enter a b c in form ax^2+bx+c\n");
   scanf("%d%d%d",&a,&b,&c);
   disc=b*b-4*a*c;
   if(a<0)
   {
      a=-a;
      b=-b;
      c=-c;
   }
   if(a==0)
       printf("Wrong values. 'a' cannot be zero\n");
   else if(disc==0)
   {
       r1=-1.0*b/(2*a);
       printf("Roots are equal and are %f and %f\n",r1,r1);
   }
   else if(disc>0)
   {
       r1=(-1.0*b/(2*a))+sqrt(disc)/(2*a);
       r2=(-1.0*b/(2*a))-sqrt(disc)/(2*a);
       printf("Roots are unequal and are %f and %f\n",r1,r2);
   }
   else
   {
       r1=-1.0*b/(2*a);
       im=sqrt(-disc)/(2*a);
       printf("Roots are imaginary and are %f + i%f and %f - i%f\n",r1,im,r1,im);
   }
}