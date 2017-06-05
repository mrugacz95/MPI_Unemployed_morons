//
// Created by tommy on 31.05.17.
//

#include <mpi.h>
#include "Messanger.h"

void Messanger::sendToAll(std::stringstream serializedMessage, int msgTag) {
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    for (int i = 0; i < world_size; ++i) {
        if (world_rank != i)
            MPI_Send(serializedMessage.str().c_str(), (int) serializedMessage.str().length(), MPI_CHAR, i, msgTag,
                     MPI_COMM_WORLD);
    }
}
