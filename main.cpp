#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Server.h"

#define PORT 8080

int main(void) {
    server::Server server(PORT,"../main.html");
    server.getHTML();
    server.Init();
    server.Run();
    return 0;
}