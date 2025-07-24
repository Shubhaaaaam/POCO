cmake_minimum_required(VERSION 3.10)
project(P2P_Node)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(Poco REQUIRED COMPONENTS Foundation Net Util)

add_executable(P2P_Node
    src/main.cpp
    src/Node.cpp
    src/P2PMessage.cpp
    src/PeerConnection.cpp
)

target_link_libraries(P2P_Node PRIVATE Poco::Foundation Poco::Net Poco::Util)
