#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MYPORT 6490
#define BACKLOG 10

int main()
{
    int sockfd,fp,new_fd;
    struct sockaddr_in my_addr,their_addr;
    int sin_size, i = 0;
    int yes = 1;
    char buf1[20],buf2[20000];

    if((sockfd=socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        printf ("error : socket\n");
        exit(1);
    }

    if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes, sizeof(int)) == -1)
    {
        printf ("error : setsockopt\n");
        exit(1);
    }

    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(MYPORT);
    my_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(my_addr.sin_zero), '\0', 8);

    if(bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr)) ==-1)
    {
        printf ("error : bind\n");
        exit(1);
    }

    if(listen(sockfd, BACKLOG) == -1)
    {
        printf ("error : listen\n");
        exit(1);
    }

    printf("\n SERVER is online! \n SERVER: Waiting for the client........\n");
    sin_size=sizeof(struct sockaddr_in);
    if((new_fd=accept(sockfd,(struct sockaddr *)&their_addr, &sin_size))==-1)
    {
        perror("Accept");
        exit(0);
    }

    printf("\n SERVER: Got connection from %s \n", inet_ntoa(their_addr.sin_addr));
    recv(new_fd, &buf1, sizeof(buf1), 0);
    printf("File requested is %s\n", buf1);
    if((fp = open(buf1, O_RDONLY)) < 0)
    {
        printf("File not found\n");
        strcpy(buf2,"File not found");
    }
    else
    {
        printf("SERVER: %s found and ready to transfer.\n",buf1);
        read(fp,&buf2,20000);
        close(fp);
    }

    send(new_fd,&buf2,sizeof(buf2),0);
    close(new_fd);
    close(sockfd);
    printf("Transfer success \n");
    printf("\n");
    return 0;
} 
