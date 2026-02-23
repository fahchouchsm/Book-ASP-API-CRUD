    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>

    int main(void)
    {
        int sockServer, sockClient;
        struct sockaddr_in server, client;

        sockServer = socket(AF_INET, SOCK_STREAM, 0);

        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        server.sin_family = AF_INET;
        server.sin_port = htons(8080);

        bind(sockServer, (struct sockaddr*)&server, sizeof(server));

        listen(sockServer, 5);

        while (1)
        {
            char buffer[1024];
            socklen_t len = sizeof(client);
            sockClient = accept(sockServer, (struct sockaddr*)& client, &len);
            int n = recv(sockClient, buffer, sizeof(buffer), 0);
            buffer[n] = '\0';
            printf("%s", buffer);
            send(sockClient, "ok", 2, 0);
            close(sockClient);
        }
        return 0;
    }