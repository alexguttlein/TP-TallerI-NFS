#ifndef SERVER_ACCEPTOR_H
#define SERVER_ACCEPTOR_H

#include "../common/common_socket.h"
#include "../common/common_thread.h"

#include <arpa/inet.h>

class Acceptor : public Thread {
public:
    Acceptor(const char* port);
    void run() override;
    void endAccepting();

private:
    Socket socket;
    bool keepAccepting;
    void closeSocket();
};

#endif //SERVER_ACCEPTOR_H
