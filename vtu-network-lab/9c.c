#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main()
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6980);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(saddr.sin_zero), '\0', 8);

    connect(sockfd, (struct sockaddr *) &saddr, sizeof(struct sockaddr));

    char filename[100], buffer[1 << 20];
    printf ("Enter file name : ");
    scanf ("%s", filename);

    send(sockfd, filename, sizeof(filename), 0);

    recv(sockfd, buffer, sizeof(buffer), 0);

    printf ("Contents : %s\n", buffer);

    close(sockfd);

    return 0;
}
