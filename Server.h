//
// Created by 정태양 on 3/25/25.
//

#ifndef SERVER_H
#define SERVER_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace server {

class Server {
private:
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *message;
    int Port;
    char *Path;
public:
    Server(int port, char *path) {
        Port = port;
        Path = path;
    };
    void getHTML();
    void Init();
    void Run();

};

} // server

#endif //SERVER_H
