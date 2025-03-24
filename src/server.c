#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>

int main() {
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    printf("socket created\n");
    printf("sockfd: %d\n", sockfd);

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

    // bind the socket
    
    // listen

    // accept

    return 0;
}
