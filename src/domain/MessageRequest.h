//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_REQUEST_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_REQUEST_H

#include <memory>
#include "Message.h"

class MessageRequest : public Message {
public:
    MessageRequest() = default;
    MessageRequest(int agentTimestamp, int companyId);

    int companyId;

    template<class Archive>
    void serialize(Archive &archive) {
        archive(this->companyId, this->timestamp, this->type);
    }
};

typedef std::shared_ptr<MessageRequest> MessageRequestRef;
#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_REQUEST_H
