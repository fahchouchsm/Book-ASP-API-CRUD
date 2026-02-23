#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 100

typedef struct {
    int sock;
    struct sockaddr_in addr;
} client_t;

void *client_handler(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[1024];

    // Seed the random generator for this thread
    srand(time(NULL) ^ client->sock);
    int target = rand() % 100 + 1;  // random number 1-100

    printf("New client connected from %s:%d\n",
           inet_ntoa(client->addr.sin_addr),
           ntohs(client->addr.sin_port));

    send(client->sock, "Guess a number between 1 and 100:\n", 35, 0);

    while (1) {
        int bytes = recv(client->sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0) break;

        buffer[bytes] = '\0';
        int guess = atoi(buffer);

        if (guess <= 0 || guess > 100) {
            send(client->sock, "Invalid input. Enter 1-100.\n", 29, 0);
            continue;
        }

        if (guess < target) {
            send(client->sock, "Higher\n", 7, 0);
        } else if (guess > target) {
            send(client->sock, "Lower\n", 6, 0);
        } else {
            send(client->sock, "Correct! You guessed it!\n", 25, 0);
            break;
        }
    }

    printf("Client %d disconnected\n", client->sock);
    close(client->sock);
    free(client);
    pthread_exit(NULL);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket failed");
        exit(1);
    }

    int opt = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *)&server, sizeof(server));
    listen(server_sock, MAX_CLIENTS);

    printf("Server running on port %d...\n", PORT);

    while (1) {
        client_t *client = malloc(sizeof(client_t));
        socklen_t len = sizeof(client->addr);

        client->sock = accept(server_sock, (struct sockaddr *)&client->addr, &len);

        pthread_t tid;
        pthread_create(&tid, NULL, client_handler, client);
        pthread_detach(tid);
    }

    close(server_sock);
    return 0;
}
