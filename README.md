# P2P Network Overlay

This project implements a decentralized Peer-to-Peer (P2P) overlay network in C++ using the Poco C++ Libraries. Nodes can dynamically join, exchange messages, and broadcast across the network without relying on a central server.

## 🌟 Features

* **Dynamic Node Discovery:** Nodes can join the network using a JOIN protocol.
* **✉️ Message Exchange:** Direct communication between peers.
* **🎤 Broadcasting:** Send messages to all known peers.
* **⚖️ Thread-Safe Peer Registry:** Mutex-based safe peer management.
* **⌨️ Interactive CLI:** Command-line tool for managing peers and messages.
* **💡 Modular Design:** Classes for node, connection, messaging, and factories.

## ⚙️ Installation

Follow these steps to set up the project locally:

1.  **Clone the Repository:**

    ```bash
    git clone [https://github.com/Shubhaaaaam/POCO.git](https://github.com/Shubhaaaaam/POCO.git)
    cd POCO
    ```

2.  **Install Dependencies:**

    ```bash
    sudo apt-get install libpoco-dev  # For Debian/Ubuntu systems
    ```

3.  **Build with CMake:**

    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```

## 🌐 Running the Application

**Start Node A (listener):**

```bash
./P2P_Node 9000
