#include "Node.h"
#include "P2PMessage.h"
#include "PeerConnection.h"
#include "PeerConnectionFactory.h"

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <iostream>

using namespace Poco::Net;
using namespace std;

Node::Node(int port) : _port(port) {}

Node::~Node() {
    stop();
}

void Node::start() {
    try {
        ServerSocket serverSocket(_port);
        _server = std::make_unique<TCPServer>(
            new PeerConnectionFactory(this),
            serverSocket
        );
        _server->start();
        std::cout << "[Node] Listening on port " << _port << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[Node] Failed to start server: " << e.what() << std::endl;
    }
}

void Node::stop() {
    if (_server) {
        _server->stop();
        std::cout << "[Node] Server stopped." << std::endl;
    }
}

void Node::connectToPeer(const std::string& host, int port) {
    try {
        StreamSocket socket;
        socket.connect(SocketAddress(host, port));

        P2PMessage joinMsg{ MessageType::JOIN, "localhost:" + std::to_string(_port) };
        std::string serialized = joinMsg.serialize() + "\n";
        socket.sendBytes(serialized.data(), static_cast<int>(serialized.size()));

        std::cout << "[Node] Sent JOIN to " << host << ":" << port << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[Node] Connection to peer failed: " << e.what() << std::endl;
    }
}

void Node::handleJoin(const std::string& peerAddress) {
    std::lock_guard<std::mutex> lock(_mutex);
    if (_peers.find(peerAddress) == _peers.end()) {
        _peers.insert(peerAddress);
        std::cout << "[Node] Peer joined: " << peerAddress << std::endl;

        // ✅ Send JOIN back
        size_t colon = peerAddress.find(':');
        if (colon != std::string::npos) {
            std::string host = peerAddress.substr(0, colon);
            int port = std::stoi(peerAddress.substr(colon + 1));
            connectToPeer(host, port);  // This sends JOIN back
        }
    }
}

void Node::printPeers() {
    std::lock_guard<std::mutex> lock(_mutex);
    std::cout << "[Node] Current Peers:\n";
    for (const auto& peer : _peers) {
        std::cout << " - " << peer << std::endl;
    }
}

void Node::removePeer(const std::string& peer) {
    std::lock_guard<std::mutex> lock(_mutex);
    if (_peers.erase(peer)) {
        std::cout << "[Node] Peer removed: " << peer << std::endl;
    } else {
        std::cout << "[Node] Tried to remove unknown peer: " << peer << std::endl;
    }
}
void Node::sendDataToPeer(const std::string& peer, const std::string& message) {
    try {
        // Parse peer string "host:port"
        size_t colon = peer.find(':');
        if (colon == std::string::npos) {
            std::cerr << "[Node] Invalid peer format: " << peer << std::endl;
            return;
        }

        std::string host = peer.substr(0, colon);
        int port = std::stoi(peer.substr(colon + 1));

        // ✅ Debug output to verify exact connection target
        std::cout << "[Node] Attempting connection to " << host << ":" << port << std::endl;

        // Connect to peer
        Poco::Net::StreamSocket socket;
        socket.connect(Poco::Net::SocketAddress(host, port));

        // Prepare DATA message
        P2PMessage dataMsg{ MessageType::DATA, message };
        std::string serialized = dataMsg.serialize() + "\n";

        // Send the message
        socket.sendBytes(serialized.data(), static_cast<int>(serialized.size()));

        std::cout << "[Node] Sent DATA to " << peer << ": " << message << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[Node] Failed to send DATA to " << peer << ": " << e.what() << std::endl;
    }
}

void Node::broadcastData(const std::string& message) {
    std::lock_guard<std::mutex> lock(_mutex);
    for (const auto& peer : _peers) {
        sendDataToPeer(peer, message);
    }
}
