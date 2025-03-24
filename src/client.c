#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>

int main() {
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    printf("SOCKET CREATED\n");

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);

    int Sconnect = connect(sockfd, );

    return 0;
}
