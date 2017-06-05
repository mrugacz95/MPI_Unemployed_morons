//
// Created by tommy on 05.06.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_H

#include "cereal/archives/json.hpp"

class Message {
public:
    enum MESSAGE_TYPE {
        REQUEST, REPLY
    };

    Message() = default;
    Message(int timestamp, MESSAGE_TYPE type);

    MESSAGE_TYPE type;
    int timestamp;

    template<class Archive>
    void serialize(Archive &archive) {
        archive(type, timestamp);
    }
};


#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_H
