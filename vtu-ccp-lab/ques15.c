#include<stdio.h>
#include<string.h>
void reverse(char str[])
{
    int l,i;
    l=strlen(str);
    char ch;
    for(i=0;i<l/2;i++)
    {
        ch=str[i];
        str[i]=str[l-1-i];
        str[l-1-i]=ch;
    }
}
main()
{
     char input[1000];
     printf("Enter string to reverse\n");
     gets(input);
     reverse(input);
     printf("Reversed string is \n%s\n",input);
}