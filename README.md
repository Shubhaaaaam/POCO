# P2P Network Overlay: A Decentralized C++ Network Implementation

This project introduces a robust and decentralized Peer-to-Peer (P2P) overlay network, meticulously crafted in C++ utilizing the powerful Poco C++ Libraries. This architecture empowers individual nodes to dynamically integrate into the network, facilitate seamless message exchange, and broadcast critical information across the entire network topology, all without the inherent vulnerabilities and single points of failure associated with a centralized server. This design emphasizes resilience, scalability,...

---

## 🌟 Core Features and Functionalities

- **Dynamic Node Discovery (JOIN Protocol):**  
  New nodes can effortlessly discover and integrate into the existing network using a JOIN protocol. The network grows or shrinks fluidly, and peers dynamically learn about others upon joining.

- **✉️ Direct Message Exchange (Peer-to-Peer Communication):**  
  Enables low-latency, private communication between two peers without a central server.

- **🎤 Network-Wide Broadcasting:**  
  Any node can broadcast messages to all known peers efficiently to ensure eventual consistency.

- **⚖️ Thread-Safe Peer Registry (Mutex-Based Management):**  
  Manages peers using mutex-based synchronization to prevent data corruption in concurrent environments.

- **⌨️ Interactive Command-Line Interface (CLI):**  
  Send messages, broadcast, view peers, and exit via a simple interactive CLI per node.

- **💡 Modular and Extensible Design:**  
  Clearly structured into Node, PeerConnection, PeerConnectionFactory, and P2PMessage classes for maintainability.

---

## ⚙️ Comprehensive Installation Guide

### Clone the Repository

```bash
git clone https://github.com/Shubhaaaaam/POCO.git
cd POCO
```

### Install Dependencies

```bash
sudo apt-get install libpoco-dev
```

> For macOS or Windows, refer to the official [Poco C++ Libraries installation guide](https://pocoproject.org/).

### Build with CMake

```bash
mkdir build && cd build
cmake ..
make
```

---

## 🌐 Running the Application

### Start Node A (Listener)

```bash
./P2P_Node 9000
```

### Start Node B (Connect to Node A)

```bash
./P2P_Node 9001 127.0.0.1 9000
```

---

### 🖥️ CLI Commands

```text
send <peer> <message>
broadcast <message>
peers
exit
```

---

## 📁 Project Structure

```
POCO/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── Node.h / Node.cpp
│   ├── PeerConnection.h / .cpp
│   ├── PeerConnectionFactory.h / .cpp
│   └── P2PMessage.h / .cpp
└── build/
```

---

## 📊 Technology Stack

- C++17
- Poco C++ Libraries
- CMake
- TCP/IP

---

## 🧠 Modules Breakdown

### 🛠️ Node Management
Handles peer list, connection setup, JOIN and DATA messages.

### 🚀 PeerConnection
Manages socket I/O for a peer.

### 📝 Messaging
JOIN/DATA message format with string serialization.

---

## 🔍 Example Use

```bash
./P2P_Node 9000
./P2P_Node 9001 127.0.0.1 9000
```

From Node A:

```text
send 127.0.0.1:9001 Hello!
broadcast Hello everyone!
```

---

## 🚀 Future Enhancements

- 🔐 TLS/SSL
- 🔁 Auto-Reconnect
- 📊 Web UI
- 💾 Peer Persistence
- 🧭 DHT Routing
- 🌐 NAT Traversal

---

## 👤 Author

**Shubhaaaaam**  
Developed during a focused 5-day P2P sprint using C++17 and Poco.

> ⭐️ Star this project if you found it helpful!
