#include "client_class.h"

Client::Client(const char* host, const char* port) :
    protocol(host, port) {
}

void Client::run() {
    std::string input;

    while (std::getline(std::cin, input)) {

        if (input == Constants::INPUT_EXIT)
            break;

        }
}
