#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(void) {
    const char *server_ip = "10.9.9.65"; 
    const int port = 8080;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &serv.sin_addr) != 1) {
        fprintf(stderr, "Invalid server IP\n"); close(sock); return 1;
    }

    if (connect(sock, (struct sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("connect"); close(sock); return 1;
    }

    const char *msg = "Hello world";
    if (send(sock, msg, strlen(msg), 0) < 0) { perror("send"); close(sock); return 1; }
    printf("Sent to server: '%s'\n", msg);

    char buf[2048];
    ssize_t n = recv(sock, buf, sizeof(buf)-1, 0);
    if (n < 0) { perror("recv"); close(sock); return 1; }
    buf[n] = '\0';
    printf("Reply from server: '%s'\n", buf);

    close(sock);
    return 0;
}

