//
// Created by tommy on 05.06.17.
//

#include "Serializer.h"
#define JSON

#ifndef JSON
std::stringstream Serializer::serialize(MessageRequest &messageRequest) {
    std::stringstream serializedMessage;
    {
        cereal::BinaryOutputArchive binaryOutputArchive(serializedMessage);
        binaryOutputArchive(messageRequest);
    }
    return serializedMessage;
}

std::stringstream Serializer::serialize(MessageReply &messageReply) {
    std::stringstream serializedMessage;
    {
        cereal::BinaryOutputArchive binaryOutputArchive(serializedMessage);
        binaryOutputArchive(messageReply);
    }
    return serializedMessage;
}

void Serializer::deserialize(MessageRequest &messageRequest, std::stringstream &serializedMessage) {
    cereal::BinaryInputArchive binaryInputArchive(serializedMessage);
    binaryInputArchive(messageRequest);
}

void Serializer::deserialize(MessageReply &messageReply, std::stringstream &serializedMessage) {
    cereal::BinaryInputArchive binaryInputArchive(serializedMessage);
    binaryInputArchive(messageReply);
}
#endif

#ifdef JSON
std::stringstream Serializer::serialize(MessageRequest &messageRequest) {
    std::stringstream serializedMessage;
    {
        cereal::JSONOutputArchive binaryOutputArchive(serializedMessage);
        binaryOutputArchive(messageRequest);
    }
    return serializedMessage;
}

std::stringstream Serializer::serialize(MessageReply &messageReply) {
    std::stringstream serializedMessage;
    {
        cereal::JSONOutputArchive binaryOutputArchive(serializedMessage);
        binaryOutputArchive(messageReply);
    }
    return serializedMessage;
}

void Serializer::deserialize(MessageRequest &messageRequest, std::stringstream &serializedMessage) {
    cereal::JSONInputArchive binaryInputArchive(serializedMessage);
    binaryInputArchive(messageRequest);
}

void Serializer::deserialize(MessageReply &messageReply, std::stringstream &serializedMessage) {
    cereal::JSONInputArchive binaryInputArchive(serializedMessage);
    binaryInputArchive(messageReply);
}
#endif