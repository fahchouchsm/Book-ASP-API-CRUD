#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    const char *server_ip = "10.9.9.65"; // same IP as server
    const int port = 8080;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) { perror("socket"); exit(EXIT_FAILURE); }

    struct sockaddr_in serv = {0};
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &serv.sin_addr) != 1) {
        fprintf(stderr, "Invalid server IP\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    const char *msg = "Hello from Unix client";
    send(sock, msg, strlen(msg), 0);
    printf("Sent: %s\n", msg);

    char buf[2048];
    ssize_t n = recv(sock, buf, sizeof(buf) - 1, 0);
    if (n <= 0) { perror("recv"); close(sock); exit(EXIT_FAILURE); }
    buf[n] = '\0';
    printf("Reply: %s\n", buf);

    close(sock);
    return 0;
}

