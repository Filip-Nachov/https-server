#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const* argv[]) {
    // declare variables
    int sockfd, new_sockfd, Sbind, Slisten;
    struct sockaddr_in addr;

    if (sockfd = socket(AF_LOCAL, SOCK_STREAM, 0) < 0) {
        printf("SOCKET CREATION FAILED\n");
        exit(1);
    }
    

    printf("SOCKET CREATED\n");
    printf("sockfd: %d\n", sockfd);

    addr.sin_family = AF_INET;

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

    Sbind = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)); // bind
    printf("SOCKET BINDED\n");

    Slisten = listen(sockfd, 3);

    new_sockfd = accept(sockfd, NULL, NULL);

    return 0;
}
