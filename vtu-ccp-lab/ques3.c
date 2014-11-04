#include<stdio.h>
#include<math.h>
main()
{
   int num,rev=0,n;
   printf("Enter 4 digit number\n");
   scanf("%d",&num);
   int l=(int)log10(num)+1;
   if(l==4)
   {
       n=num;
   	while(num!=0)
  	 {
       		rev=rev*10+num%10;
       		num/=10;
   	}
   	if(n==rev)
    	  printf("%d is a palindrome \n",n);
   	else
     	  printf("%d is not a palindrome \n",n);
   }
   else 
      printf("Not 4 digit \n");

   
}