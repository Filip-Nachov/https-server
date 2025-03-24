#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>

#define PORT 8080

int main() {
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    printf("SOCKET CREATED\n");
    printf("sockfd: %d\n", sockfd);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

    int Sbind = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)); // bind
    printf("SOCKET BINDED\n");

    // listen
    int Slisten = listen(sockfd, 3);

    // accept
    int new_sockfd = accept(sockfd, NULL, NULL);

    return 0;
}
