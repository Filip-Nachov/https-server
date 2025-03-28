#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 8080

int sockfd;
struct sockaddr_in address;

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("SOCKET");
        exit(EXIT_FAILURE);
    }

    return 0;
}
