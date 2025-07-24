#pragma once

#include <string>
#include <set>
#include <mutex>
#include <memory>
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnectionFactory.h>

class Node {
public:
    Node(int port);
    ~Node();

    void start();
    void stop();

    void connectToPeer(const std::string& host, int port);
    void handleJoin(const std::string& peerAddress);

    void printPeers();
    void removePeer(const std::string& peer);

    void sendDataToPeer(const std::string& peer, const std::string& message);
    void broadcastData(const std::string& message);

private:
    int _port;
    std::set<std::string> _peers;
    std::mutex _mutex;

    std::unique_ptr<Poco::Net::TCPServer> _server;
    
};
