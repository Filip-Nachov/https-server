#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[]) {
    // declare variables
    int sockfd, new_sockfd, Sbind, Slisten;
    ssize_t valread;
    struct sockaddr_in address;
    int opt = 1;
    char buffer[1024] = { 0 };
    socklen_t addrlen = sizeof(address);

    if (sockfd = socket(AF_LOCAL, SOCK_STREAM, 0) < 0) {
        perror("Socket creation failer");
        exit(EXIT_FAILURE);
    }
    printf("SOCKET CREATED\n");
    printf("sockfd: %d\n", sockfd);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsocketopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    Sbind = bind(sockfd, (struct sockaddr*)&address, sizeof(address)); // bind
    printf("SOCKET BINDED\n");

    Slisten = listen(sockfd, 3);

    new_sockfd = accept(sockfd, NULL, NULL);

    return 0;
