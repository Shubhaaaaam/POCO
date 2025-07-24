// src/P2PMessage.cpp
#include "P2PMessage.h"

std::string P2PMessage::serialize() const {
    return std::to_string(static_cast<int>(type)) + "|" + content;
}

P2PMessage P2PMessage::deserialize(const std::string& raw) {
    auto delimiter = raw.find('|');
    if (delimiter == std::string::npos) return {MessageType::UNKNOWN, ""};
    
    int type = std::stoi(raw.substr(0, delimiter));
    std::string content = raw.substr(delimiter + 1);

    return {static_cast<MessageType>(type), content};
}
