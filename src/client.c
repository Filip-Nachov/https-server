#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>

int main() {
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    printf("SOCKET CREATED\n");

    return 0;
}
