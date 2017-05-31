//
// Created by tommy on 31.05.17.
//

#include <mpi.h>
#include "Messanger.h"

void Messanger::sendToAll(std::string serializedMessage, int msgTag) {
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    for (int i = 0; i < world_size; ++i) {
        MPI_Send(serializedMessage.c_str(), serializedMessage.length(), MPI_CHAR, i, msgTag, MPI_COMM_WORLD);
    }
}
