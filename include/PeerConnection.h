#pragma once

#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/StreamSocket.h>
#include <string>

class Node; // forward declaration

class PeerConnection : public Poco::Net::TCPServerConnection {
public:
    PeerConnection(const Poco::Net::StreamSocket& socket, Node* node);
    void run() override;

private:
    Node* _node; // pointer back to the parent node
};
