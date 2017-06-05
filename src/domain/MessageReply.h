//
// Created by tommy on 05.06.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGEREPLY_H
#define MPI_UNEMPLOYED_MORONS_MESSAGEREPLY_H

#include "Message.h"
#include "Company.h"

class MessageReply: public Message {
public:
    MessageReply(Company company, int agentTimestamp);
};


#endif //MPI_UNEMPLOYED_MORONS_MESSAGEREPLY_H
