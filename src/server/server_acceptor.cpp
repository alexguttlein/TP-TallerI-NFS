#include "server_acceptor.h"

Acceptor::Acceptor(const char* port) :
    socket(port),
    keepAccepting(true) {}

void Acceptor::run() {
    int id = 0;
    while (keepAccepting && !socket.is_stream_recv_closed()) {
        try {
            // se acepta un nuevo cliente
            Socket newSocket = socket.accept();

            id++;
        } catch (const std::exception& e) {
            if (keepAccepting) {
                std::cerr << "Unexpected exception: " << e.what() << std::endl;
            }
            break;
        }
    }
}

void Acceptor::endAccepting() {
    keepAccepting = false;
    closeSocket();
}

void Acceptor::closeSocket() {
    if (!socket.is_stream_recv_closed() && !socket.is_stream_send_closed()) {
        this->socket.shutdown(SHUT_RDWR);
        this->socket.close();
    }
}
