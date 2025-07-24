// include/P2PMessage.h
#pragma once
#include <string>

enum class MessageType {
    JOIN,
    DATA,
    PING,
    PONG,
    UNKNOWN
};

struct P2PMessage {
    MessageType type;
    std::string content;

    std::string serialize() const;
    static P2PMessage deserialize(const std::string& raw);
};
