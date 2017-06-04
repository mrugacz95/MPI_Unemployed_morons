/* C Example */
#include <mpi.h>
#include "domain/Configuration.h"
#include "domain/Agent.h"

#include "utils/JsonLoader.h"
#include "jsonConverters/ConfigurationJsonConverter.h"

int main(int argc, char *argv[]) {
    int rank, agentsNumber;

    JsonRef configJson = JsonLoader::loadJson("src/config.json");
    ConfigurationJsonConverter::getFromJson(configJson);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &agentsNumber);

    Agent agent(rank, agentsNumber);
    agent.run();

    MPI_Finalize();
    return 0;
}