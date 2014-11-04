#include<stdio.h>
#include<string.h>
main()
{
     char input[1000],str[1000];
     int l,i,j=0;
     printf("Enter string with spaces\n");
     gets(input);
     l=strlen(input);
     for(i=0;i<l;i++)
     {
         if(input[i]!=' ')
             str[j++]=input[i];
         else
         {
             if(j!=0)
                 str[j++]=' ';
             while(input[++i]==' '&&i<l);
             i--;
         }
     }
     str[j++]='\0';
     printf("String after removing spaces is\n%s",str);
}