#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024 

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Connection failed");
    exit(1);
  }

  printf("Connected to server!\n");

  char buffer[BUFFER_SIZE];
  while (1) {
    // Receive server message
    int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0) {
      printf("Server disconnected.\n");
      break;
    }
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Get user input
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      break;
    }

    // Send guess to server
    send(sock, buffer, strlen(buffer), 0);
  }

  close(sock);
  return 0;
}
