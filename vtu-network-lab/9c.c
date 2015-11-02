#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 6490
int main()
{
    int i = 0, sockfd, len;
    char buf1[40], buf2[20000];

    struct sockaddr_in saddr;

    if((sockfd=socket(AF_INET, SOCK_STREAM,0)) == -1)
    {
        printf ("error : socket\n");
        exit(1);
    }         
                                             
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(saddr.sin_zero), '\0', 8);
    if(connect(sockfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr))==-1)
    {
        printf ("error : connect\n");
        exit(1);
    }

    printf("CLIENT is online!\n");
    printf("CLIENT:Enter the filename to be displayed: ");
    scanf("%s", buf1);
    send(sockfd, buf1, sizeof(buf1), 0);
    if(recv(sockfd, buf2, sizeof(buf2), 0) == 1)
    {
        printf ("error : recv\n");
        exit(1);
    }
    else
    {
        printf("Displyaing the contents of %s", buf1);
        printf("\n%s\n",buf2);
    }
    close(sockfd);
    return 0;
}
