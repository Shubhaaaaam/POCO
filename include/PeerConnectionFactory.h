// include/PeerConnectionFactory.h
#pragma once

#include "Node.h"
#include "PeerConnection.h"
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerConnection.h>

class PeerConnectionFactory : public Poco::Net::TCPServerConnectionFactory {
public:
    PeerConnectionFactory(Node* node) : _node(node) {}

    Poco::Net::TCPServerConnection* createConnection(const Poco::Net::StreamSocket& socket) override {
        return new PeerConnection(socket, _node);
    }

private:
    Node* _node;
};
