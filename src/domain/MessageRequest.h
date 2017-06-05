//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_H

#include <memory>

struct MessageRequest {
    int companyId;
    int timestamp;
};

typedef std::shared_ptr<MessageRequest> MessageRef;
#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_H
