# P2P Network Overlay: A Decentralized C++ Network Implementation

This project introduces a robust and decentralized Peer-to-Peer (P2P) overlay network, meticulously crafted in C++ utilizing the powerful Poco C++ Libraries. This architecture empowers individual nodes to dynamically integrate into the network, facilitate seamless message exchange, and broadcast critical information across the entire network topology, all without the inherent vulnerabilities and single points of failure associated with a centralized server. This design emphasizes resilience, scalability, and direct peer communication, laying a foundational block for distributed systems.

## 🌟 Core Features and Functionalities

Our P2P Network Overlay is built upon a set of key features designed to ensure efficient and reliable decentralized communication:

* **Dynamic Node Discovery (JOIN Protocol):** At the heart of this network lies a sophisticated `JOIN` protocol. New nodes can effortlessly discover and integrate themselves into the existing network. This dynamic discovery mechanism ensures that the network can grow or shrink fluidly, adapting to the presence or absence of peers without manual configuration. Upon joining, a new node can announce its presence and receive information about other active peers, establishing its initial connections.

* **✉️ Direct Message Exchange (Peer-to-Peer Communication):** The system facilitates direct, point-to-point communication between any two connected peers. This means messages are routed directly from the sender to the intended recipient, minimizing latency and maximizing privacy compared to centralized messaging systems. This direct exchange is crucial for targeted communication within the network.

* **🎤 Network-Wide Broadcasting:** Beyond direct messaging, the overlay supports a robust broadcasting mechanism. Any node can initiate a broadcast message, which is then efficiently propagated to all other known peers within the network. This feature is invaluable for disseminating critical updates, announcements, or general information to the entire community of connected nodes. The broadcast mechanism is designed to ensure eventual consistency across all active participants.

* **⚖️ Thread-Safe Peer Registry (Mutex-Based Management):** To ensure data integrity and prevent race conditions in a multi-threaded environment, the management of peer connections is handled by a thread-safe registry. This registry utilizes mutexes to synchronize access to the list of active peers, guaranteeing that concurrent operations (like adding or removing peers) do not corrupt the network state. This robust approach is vital for the stability and reliability of a dynamic P2P network.

* **⌨️ Interactive Command-Line Interface (CLI):** For ease of use and immediate interaction, the project includes an intuitive command-line interface. This CLI provides users with a powerful tool to manage their node, send messages to specific peers, initiate network-wide broadcasts, and query the current list of connected peers. This interactive environment simplifies testing, debugging, and general operation of the P2P node.

* **💡 Modular and Extensible Design:** The entire project adheres to a modular design philosophy, separating concerns into distinct classes. This includes dedicated classes for the main `Node` logic, `PeerConnection` handling, `P2PMessage` structures, and `PeerConnectionFactory` for creating new connections. This modularity enhances code readability, maintainability, and extensibility, making it easier to introduce new features or modify existing ones without affecting the entire codebase.

## ⚙️ Comprehensive Installation Guide

To get your P2P Network Overlay up and running on your local machine, follow these detailed steps:

1.  **Clone the Repository:**
    Begin by cloning the project's source code from its GitHub repository to your local development environment. This command will download the entire project structure.

    ```bash
    git clone [https://github.com/Shubhaaaaam/POCO.git](https://github.com/Shubhaaaaam/POCO.git)
    cd POCO
    ```

2.  **Install Dependencies:**
    This project relies on the Poco C++ Libraries for its networking and utility functionalities. For Debian/Ubuntu-based systems, you can install the necessary development files using `apt-get`. For other Linux distributions, macOS, or Windows, please refer to the Poco documentation for the appropriate installation method.

    ```bash
    sudo apt-get install libpoco-dev  # For Debian/Ubuntu systems
    ```

3.  **Build with CMake:**
    We use CMake as our build system generator. First, create a `build` directory to keep your source directory clean. Then, navigate into it and run `cmake ..` to configure the project. Finally, `make` will compile the source code and generate the executable.

    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```

    Upon successful compilation, the executable `P2P_Node` will be available within the `build/` directory.

## 🌐 Running the Application: A Step-by-Step Walkthrough

Once built, you can launch multiple nodes to simulate a P2P network. Each node requires a unique port to listen on.

**Start Node A (Listener - First Node in the Network):**
This command starts the first node, which will act as a listener on port 9000. It doesn't connect to any existing peer initially, waiting for others to join it.

```bash
./P2P_Node 9000
