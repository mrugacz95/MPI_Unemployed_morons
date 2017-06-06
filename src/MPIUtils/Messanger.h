//
// Created by tommy on 31.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSANGER_H
#define MPI_UNEMPLOYED_MORONS_MESSANGER_H

#include <sstream>

class Messanger {
public:
    static void sendToAll(std::stringstream &serializedMessage, int msgTag);

    static std::stringstream receiveFromAny(int msgTag);

    static int getMessageLength(int msgTag);

    static int getNextTag();

    static int getSender();
};

#endif //MPI_UNEMPLOYED_MORONS_MESSANGER_H
