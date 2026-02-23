#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

int main(void)
{
  const char *server_ip = "127.0.0.1";
  const int port = 8080;

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serv = {0};
  serv.sin_family = AF_INET;
  serv.sin_port = htons(port);
  if (inet_pton(AF_INET, server_ip, &serv.sin_addr) != 1)
  {
    fprintf(stderr, "Invalid server IP\n");
    close(sock);
    exit(EXIT_FAILURE);
  }

  if (connect(sock, (struct sockaddr *)&serv, sizeof(serv)) < 0)
  {
    perror("connect");
    close(sock);
    exit(EXIT_FAILURE);
  }

  printf("Connected to server %s:%d\n", server_ip, port);

  fd_set readfds;
  char buf[1024], msg[1024];

  while (1)
  {
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    FD_SET(sock, &readfds);

    int max_fd = sock > STDIN_FILENO ? sock : STDIN_FILENO;
    int activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);
    if (activity < 0 && errno != EINTR)
    {
      perror("select");
      break;
    }

    if (FD_ISSET(sock, &readfds))
    {
      ssize_t n = recv(sock, buf, sizeof(buf) - 1, 0);
      if (n <= 0)
      {
        printf("Server disconnected.\n");
        break;
      }
      buf[n] = '\0';
      if (strcmp(buf, "exit") == 0)
      {
        printf("Server closed the connection.\n");
        break;
      }
      printf("Server: %s\n", buf);
    }

    if (FD_ISSET(STDIN_FILENO, &readfds))
    {
      if (!fgets(msg, sizeof(msg), stdin))
        break;
      msg[strcspn(msg, "\n")] = '\0';
      if (strcmp(msg, "exit") == 0)
      {
        send(sock, msg, strlen(msg), 0);
        printf("Connection closed.\n");
        break;
      }
      send(sock, msg, strlen(msg), 0);
    }
  }

  close(sock);
  return 0;
}
