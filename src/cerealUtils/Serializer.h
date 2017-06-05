//
// Created by tommy on 05.06.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_SERIALIZER_H
#define MPI_UNEMPLOYED_MORONS_SERIALIZER_H


#include <sstream>
#include "../domain/MessageRequest.h"
#include "../domain/MessageReply.h"

class Serializer {
public:
    static std::stringstream serialize(MessageRequest messageRequest);
    static std::stringstream serialize(MessageReply messageReply);
};


#endif //MPI_UNEMPLOYED_MORONS_SERIALIZER_H
