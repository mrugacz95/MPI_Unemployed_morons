//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_H

#include <memory>

struct Message {
    enum TYPE {REQUEST,REPLAY};
    TYPE type;
    int companyId;
    int timestamp;
};

typedef std::shared_ptr<Message> MessageRef;
#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_H
