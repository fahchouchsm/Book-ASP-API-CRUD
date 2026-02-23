cmake_minimum_required(VERSION 3.15)
project(servClient C)

set(CMAKE_C_STANDARD 11)

# Server executable
add_executable(server
        server.c
)

# Client executable
add_executable(client
        client.c
)
