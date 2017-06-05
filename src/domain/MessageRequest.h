//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_REQUEST_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_REQUEST_H

#include <memory>
#include "Message.h"

class MessageRequest: public Message {
    int companyId;
public:
    int timestamp;
};

typedef std::shared_ptr<MessageRequest> MessageRef;
#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_REQUEST_H
