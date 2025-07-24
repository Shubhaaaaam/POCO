#include "PeerConnection.h"
#include "P2PMessage.h"
#include "Node.h"

#include <Poco/Net/SocketStream.h>
#include <iostream>
#include <sstream>

using namespace Poco::Net;
using namespace std;

PeerConnection::PeerConnection(const StreamSocket& socket, Node* node)
    : TCPServerConnection(socket), _node(node) {}

void PeerConnection::run() {
    try {
        SocketStream stream(socket());
        std::string raw;
        std::getline(stream, raw);
        std::cout << "[PeerConnection] RAW received: '" << raw << "'" << std::endl;

        if (raw.empty()) {
            std::cout << "[PeerConnection] Empty message received." << std::endl;
            return;
        }

        auto message = P2PMessage::deserialize(raw);

        switch (message.type) {
            case MessageType::JOIN: {
            std::cout << "[PeerConnection] Received JOIN: " << message.content << std::endl;
            break;
        }
            case MessageType::DATA:
                std::cout << "[PeerConnection] Received DATA: " << message.content << std::endl;
                break;

            default:
                std::cout << "[PeerConnection] Unknown or unhandled message received: " << raw << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "[PeerConnection] Error: " << e.what() << std::endl;
    }
}
