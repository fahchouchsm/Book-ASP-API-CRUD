#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

void handle_client(int client_fd)
{
    char buffer[BUF_SIZE];
    int n;

    // Message loop
    while ((n = recv(client_fd, buffer, BUF_SIZE - 1, 0)) > 0)
    {
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);
        send(client_fd, buffer, n, 0);
    }

    printf("Client disconnected.\n");
    close(client_fd);
}

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // 1️⃣ Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("Socket failed"); exit(1); }

    // 2️⃣ Allow address reuse
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 3️⃣ Server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 4️⃣ Bind
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))

    // 5️⃣ Listen
    listen(server_fd, 10);
    printf("Server running on port %d...\n", PORT);

    while (1)
    {
        printf("Waiting for a client...\n");
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);


        printf("Client connected!\n");

        handle_client(client_fd);
    }

    close(server_fd);
    return 0;
}
