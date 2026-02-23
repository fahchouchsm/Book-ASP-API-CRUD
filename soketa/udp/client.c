#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main()
{
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[BUF_SIZE];
  int n;

  // 1️⃣ Create socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("Socket failed");
    exit(1);
  }

  // 2️⃣ Server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // 3️⃣ Connect
  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  printf("Connected to server. Type messages:\n");

  while (1)
  {
    // Read from stdin
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
      break;

    // Send to server
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    n = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    if (n <= 0) break;

    buffer[n] = '\0';
    printf("Server: %s", buffer);
  }

  close(sockfd);
  printf("\nDisconnected.\n");
  return 0;
}
