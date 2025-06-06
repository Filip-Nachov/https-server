#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int sockfd, new_socket;
ssize_t valread;
struct sockaddr_in address;
int opt = 1;
char buffer[1024] = { 0 };
socklen_t addrlen = sizeof(address);


int main() {

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("SOCKET");
        exit(EXIT_FAILURE);
    }
    printf("SOCKET CREATED\n");
    printf("sockfd: %d\n", sockfd);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsocketopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (-1 == (bind(sockfd, (struct sockaddr*)&address, sizeof(address)))) {
       perror("BIND");
       exit(EXIT_FAILURE);
    }; 
    printf("SOCKET BINDED\n");

    if (listen(sockfd, 3) < 0) {
        perror("LISTEN");
        exit(EXIT_FAILURE);
    }
    
    new_socket = accept(sockfd, NULL, NULL);
    if (new_socket < 0) {
        perror("ACCEPT");
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, 1024 - 1);
    printf("%s\n", buffer);
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Hello message sent\n");

    close(new_socket);

    close(sockfd);

    return 0;
}
