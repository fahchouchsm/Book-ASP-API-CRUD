#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    const char *bind_ip = "10.9.9.65"; // your server IP
    const int port = 8080;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) { perror("socket"); exit(EXIT_FAILURE); }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, bind_ip, &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid IP address\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s:%d\n", bind_ip, port);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) { perror("accept"); close(server_fd); exit(EXIT_FAILURE); }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    printf("Connection from %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    char buf[1024];
    ssize_t n = recv(client_fd, buf, sizeof(buf) - 1, 0);
    if (n <= 0) { perror("recv"); close(client_fd); close(server_fd); exit(EXIT_FAILURE); }
    buf[n] = '\0';
    printf("Received: %s\n", buf);

    char reply[2048];
    snprintf(reply, sizeof(reply), "Server got your message: %s", buf);
    send(client_fd, reply, strlen(reply), 0);

    close(client_fd);
    close(server_fd);
    printf("Connection closed.\n");
    return 0;
}

