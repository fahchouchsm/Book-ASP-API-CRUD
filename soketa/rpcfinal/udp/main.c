#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(void) {
    int sockett;
    struct sockaddr_in server, client;
    char buffer[1024];
    sockett = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    bind(sockett, (struct sockaddr*)& server, sizeof(server));

    while (1)
    {
        socklen_t len = sizeof(client);
        int n = recvfrom(sockett, buffer, 1024, 0, (struct sockaddr*)&client, &len);
        buffer[n] = '\0';
        printf("client : %s\n", buffer);

        const char *reply = "ok";
        sendto(sockett, reply, strlen(reply), 0, (struct sockaddr*) &client,len);
    }

    close(sockett);
    return 0;
}