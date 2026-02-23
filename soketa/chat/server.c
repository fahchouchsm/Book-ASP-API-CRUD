#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define NAME_SIZE 50

void handle_client(int client_fd)
{
  char buf[BUFFER_SIZE];
  char name[NAME_SIZE] = "";

  const char *question = "Quelle est votre nom ? ";
  send(client_fd, question, strlen(question), 0);

  ssize_t n = recv(client_fd, name, sizeof(name) - 1, 0);
  if (n <= 0)
  {
    close(client_fd);
    return;
  }
  name[n] = '\0';
  name[strcspn(name, "\n")] = '\0';
  printf("%s joined the chat\n", name);

  char welcome[BUFFER_SIZE];
  snprintf(welcome, sizeof(welcome), "Bienvenue %s!\n", name);
  send(client_fd, welcome, strlen(welcome), 0);

  while (1)
  {
    n = recv(client_fd, buf, sizeof(buf) - 1, 0);
    if (n <= 0)
      break;

    buf[n] = '\0';
    buf[strcspn(buf, "\n")] = '\0';
    if (strcmp(buf, "exit") == 0)
    {
      printf("%s left the chat\n", name);
      break;
    }

    printf("%s > %s\n", name, buf);

    char msg[BUFFER_SIZE + NAME_SIZE];
    snprintf(msg, sizeof(msg), "%s > %s\n", name, buf);
    send(client_fd, msg, strlen(msg), 0);
  }

  close(client_fd);
}

int main()
{
  const char *ip = "127.0.0.1";
  int port = 8080;

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0)
  {
    perror("socket");
    exit(1);
  }

  int opt = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  inet_pton(AF_INET, ip, &addr.sin_addr);

  if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
  {
    perror("bind");
    exit(1);
  }
  if (listen(server_fd, 5) < 0)
  {
    perror("listen");
    exit(1);
  }

  printf("Server listening on %s:%d\n", ip, port);

  while (1)
  {
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);
    if (client_fd < 0)
    {
      perror("accept");
      continue;
    }

    pid_t pid = fork();

    if (pid == 0)
    {

      close(server_fd);
      handle_client(client_fd);
      exit(0);
    }
    else
    {

      close(client_fd);
    }
  }

  close(server_fd);
  return 0;
}
