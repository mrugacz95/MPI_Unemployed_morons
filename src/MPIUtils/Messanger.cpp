//
// Created by tommy on 31.05.17.
//

#include <mpi.h>
#include "Messanger.h"
#include "../domain/MessageRequest.h"
#include "../domain/Agent.h"

void Messanger::sendToAll(std::stringstream &serializedMessage, int msgTag) {
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    for (int i = 0; i < world_size; ++i) {
        if (world_rank != i)
            MPI_Send(serializedMessage.str().c_str(), (int) serializedMessage.str().length()+1, MPI_CHAR, i, msgTag,
                     MPI_COMM_WORLD);
    }
}

std::stringstream Messanger::receiveFromAny(int msgTag) {
    int count = getMessageLength(msgTag);
    char* recvMessage = new char[count];
    MPI_Recv(recvMessage, count, MPI_CHAR, MPI_ANY_SOURCE, msgTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    std::stringstream toReturn(recvMessage);
    return toReturn;
}

int Messanger::getMessageLength(int msgTag) {
    MPI_Status status;
    int count;
    MPI_Probe(MPI_ANY_SOURCE, msgTag, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_CHAR, &count);
    return count;
}