
🔸 Peer-to-Peer (P2P) Network Overlay - C++ with Poco

This project implements a decentralized Peer-to-Peer (P2P) overlay network in C++ using the Poco C++ Libraries. Nodes can dynamically join, exchange messages, and broadcast across the network without a central server.

🚀 Features

🌐 Dynamic node discovery (JOIN protocol)

🔄 Real-time peer-to-peer message exchange

📢 Broadcast messages to all known peers

🥵 Thread-safe peer registry

💻 CLI interface for interaction

⚙️ Built using Poco C++ Libraries

🏧 Architecture

🏈 Node A ➜ JOIN ➜ Node B
   (9000)                    (9001)
    └➜ CLI                └➜ CLI
     └➜ Server            └➜ Server
      └➜ SEND ←→ DATA ←→ JOIN

Core Components

File

Description

main.cpp

CLI runner & bootstrap logic

Node.{h,cpp}

Server, client, peer tracking

PeerConnection.{h,cpp}

Handles incoming messages per connection

PeerConnectionFactory

Factory for socket handling threads

P2PMessage.{h,cpp}

Message serialization and parsing

🧰 Dependencies

C++17 or higher

Poco C++ Libraries

cmake

⚙️ Build Instructions

git clone https://github.com/yourusername/p2p-overlay-cpp.git
cd p2p-overlay-cpp
mkdir build && cd build
cmake ..
make

▶️ Run Instructions

Start a Node A (Server mode)

./P2P_Node 9000

Start Node B and connect to A

./P2P_Node 9001 127.0.0.1 9000

🧪 CLI Commands

Command

Description

peers

List connected peers

send <peer> <msg>

Send a direct message

broadcast <msg>

Send message to all known peers

exit

Exit the node

Example:

send 127.0.0.1:9000 Hello from Node B!
broadcast Hello everyone!

🤩 Future Enhancements

TLS-secured communication

Persistent peer caching

NAT traversal (UDP hole punching)

GUI or web interface for peer maps

Heartbeat monitoring for peer liveness

🧑‍💻 Author

ShubhaaaaamBuilt as a multi-day networking overlay project in C++.

📄 License

This project is licensed under the MIT License.

