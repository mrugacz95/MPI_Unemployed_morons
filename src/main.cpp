/* C Example */
#include <mpi.h>
#include "domain/Configuration.h"
#include "domain/Agent.h"

#include "include/Json.h"
#include "jsonConverters/ConfigurationJsonConverter.h"
#include <fstream>

int main(int argc, char *argv[]) {
    int rank, agentsNumber;

    std::ifstream jsonStream("src/domain/config.json");
    Json configJson;
    jsonStream >> configJson;
    ConfigurationJsonConverter::getFromJson(configJson);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &agentsNumber);

    Agent agent(rank,agentsNumber);
    agent.run();

    MPI_Finalize();
    return 0;
}