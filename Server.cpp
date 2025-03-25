//
// Created by 정태양 on 3/25/25.
//

#include "Server.h"

namespace server {
    void Server::getHTML() {
        std::string line, res = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=utf-8\nContent-Length: 200\n\n";
        std::ifstream file(Path);
        if (file.is_open()) {
            while (getline(file, line)) {
                res.append(line);
            }
        }else {
            perror("error opening file");
        }
        message = (char*)malloc(res.length() + 1);
        strcpy(message, res.c_str());
    }
    void Server::Init() {
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }
        int opt = 1;
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(Port);

        memset(address.sin_zero, 0, sizeof(address.sin_zero));

        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        {
            perror("In bind");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 10) < 0)
        {
            perror("In listen");
            exit(EXIT_FAILURE);
        }
    }
    void Server::Run() {
        for (;;) {
            printf("\n========== Waiting for new connection ==========\n\n");
            system("netstat -an | grep 8080");
            printf("-----------------------\n");
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
            {
                perror("In accept");
                exit(EXIT_FAILURE);
            }
            system("netstat -an | grep 8080");
            printf("-----------------------\n");
            char buffer[30000] = {0};
            valread = read(new_socket, buffer, 30000);
            printf("%s\n", buffer);
            system("netstat -an | grep 8080");
            write(new_socket, message, strlen(message));
            printf("------------------message sent-------------------\n");
            close(new_socket);
        }
    }
} // server