#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(void) {
    const char *bind_ip = "10.9.9.65"; // YOUR IP
    const int port = 8080;

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) { perror("socket"); return 1; }

    int opt = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, bind_ip, &addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid bind IP\n"); close(listen_fd); return 1;
    }

    if (bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); close(listen_fd); return 1;
    }

    if (listen(listen_fd, 5) < 0) { perror("listen"); close(listen_fd); return 1; }
    printf("Server listening on %s:%d\n", bind_ip, port);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) { perror("accept"); close(listen_fd); return 1; }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    printf("Connection from %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    char buf[1024];
    ssize_t n = recv(client_fd, buf, sizeof(buf)-1, 0);
    if (n < 0) { perror("recv"); close(client_fd); close(listen_fd); return 1; }
    buf[n] = '\0';
    printf("Received from client: '%s'\n", buf);

    const char *reply_prefix = "Server received: ";
    char reply[2048];
    snprintf(reply, sizeof(reply), "%s%s", reply_prefix, buf);

    if (send(client_fd, reply, strlen(reply), 0) < 0) { perror("send"); }

    close(client_fd);
    close(listen_fd);
    printf("Server: connection closed.\n");
    return 0;
}

