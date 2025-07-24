#include "Node.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

int main(int argc, char** argv) {
    if (argc != 2 && argc != 4) {
        std::cerr << "Usage:\n"
                  << "  Server-only mode: " << argv[0] << " <port>\n"
                  << "  Join mode:        " << argv[0] << " <port> <peer_ip> <peer_port>\n";
        return 1;
    }

    int myPort = std::stoi(argv[1]);
    Node node(myPort);
    std::atomic<bool> running{true};

    // ✅ Always start the server listener first
    node.start();
    std::cout << "[main] Server started on port " << myPort << std::endl;

    // ✅ Optionally connect to another peer if provided
    if (argc == 4) {
        std::string peerIp = argv[2];
        int peerPort = std::stoi(argv[3]);
        node.connectToPeer(peerIp, peerPort);
    }

    std::cout << "[main] Node is running. Type commands: send, broadcast, peers, exit\n";

    // 🔁 Peer list printer every 10 seconds
    std::thread printerThread([&node, &running]() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(1000));
            if (running) node.printPeers();
        }
    });

    // 🔁 User input command handler
    std::thread inputThread([&node, &running]() {
        while (running) {
            std::string cmd;
            std::getline(std::cin, cmd);

            if (cmd.rfind("send ", 0) == 0) {
                size_t space = cmd.find(' ', 5);
                if (space != std::string::npos) {
                    std::string peer = cmd.substr(5, space - 5);
                    std::string msg = cmd.substr(space + 1);
                    node.sendDataToPeer(peer, msg);
                } else {
                    std::cout << "Usage: send <peer> <message>\n";
                }
            } else if (cmd.rfind("broadcast ", 0) == 0) {
                node.broadcastData(cmd.substr(10));
            } else if (cmd == "peers") {
                node.printPeers();
            } else if (cmd == "exit") {
                std::cout << "[main] Exiting...\n";
                running = false;
                break;
            } else {
                std::cout << "Commands:\n";
                std::cout << "  send <peer> <message>\n";
                std::cout << "  broadcast <message>\n";
                std::cout << "  peers\n";
                std::cout << "  exit\n";
            }
        }
    });

    // 🔒 Join threads and shut down cleanly
    inputThread.join();
    printerThread.join();
    node.stop();

    return 0;
}
