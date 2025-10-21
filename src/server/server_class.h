#ifndef SERVER_CLASS_H
#define SERVER_CLASS_H

#include "../common/common_socket.h"
#include "../common/common_queue.h"
#include "server_acceptor.h"

#include <iostream>
#include <ostream>
#include <unistd.h>
#include <string>

class Server {
public:
    explicit Server(const char* port);
    void run();
private:
    Acceptor acceptor;
    void closeAcceptor();
};

#endif //SERVER_CLASS_H