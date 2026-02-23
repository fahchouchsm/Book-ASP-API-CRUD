#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void)
{
    int sockett;
    struct sockaddr_in server;
    char buffer[1024];

    sockett = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    strcpy(buffer, "hello from the client");

    sendto(sockett, buffer, strlen(buffer), 0, (struct sockaddr*) &server, sizeof(server));

    socklen_t serverLen = sizeof(server);
    int n = recvfrom(sockett, buffer, sizeof(buffer),0, (struct sockaddr*)& server, &serverLen);
    buffer[n] = '\0';
    printf("%s", buffer);
    close(sockett);
    return 0;
}