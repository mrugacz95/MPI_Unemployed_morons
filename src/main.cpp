/* C Example */
#include <fstream>
#include "cereal/archives/json.hpp"

#include <mpi.h>
#include "domain/Agent.h"
#include "domain/Configuration.h"


int main(int argc, char *argv[]) {
    int rank, agentsNumber;

    std::ifstream inStream("configuration.json");
    cereal::JSONInputArchive jsonInArchive(inStream);

    Configuration configuration;

    jsonInArchive(configuration);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &agentsNumber);

    std::cout << "Hello from thread" << rank << " | "
              << "morons per agent:" << configuration.initialMoronsNumberPerAgent << " | "
              << "  company:" << " | "
              << "      max damage: " << configuration.companies[0].maxDamageLevel << " | "
              << "      max morons: " << configuration.companies[0].maxMorons << std::endl;

    MPI_Finalize();
    return 0;

    Agent agent(rank, agentsNumber, configuration.initialMoronsNumberPerAgent);
    agent.run();

    MPI_Finalize();
    return 0;
}