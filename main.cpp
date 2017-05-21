/* C Example */
#include <mpi.h>
#include "Configuration.h"
#include "Message.h"
#include "Agent.h"

int main(int argc, char *argv[]) {
    int rank, agentsNumber;


    Configuration::loadConfiguration();

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &agentsNumber);

    Agent agent(rank,agentsNumber);
    agent.run();

    MPI_Finalize();
    return 0;
}