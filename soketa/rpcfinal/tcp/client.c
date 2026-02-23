#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void)
{
    int sock;
    struct sockaddr_in server;
    char buffer[1024];

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    strcpy(buffer, "hello using tcp");
    send(sock, buffer, strlen(buffer), 0);

    int n = recv(sock, buffer, sizeof(buffer), 0);
    buffer[n] = '\0';
    printf("%s", buffer);
    close(sock);
    return 0;

}