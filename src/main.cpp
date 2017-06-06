/* C Example */
#include <fstream>

#include <mpi.h>
#include "domain/Agent.h"
#include "MPIUtils/Messanger.h"
#include "cerealUtils/Serializer.h"


int main(int argc, char *argv[]) {
    int rank, agentsNumber;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &agentsNumber);

    std::ifstream inStream("configuration.json");
    cereal::JSONInputArchive jsonInArchive(inStream);

    Configuration configuration;

    jsonInArchive(configuration);

    std::cout << "Hello from thread: " << rank << " | "
              << "morons per agent:" << configuration.initialMoronsNumberPerAgent << " | "
              << "company:" << " | "
              << "max damage: " << configuration.companies[0].maxDamageLevel << " | "
              << "max morons: " << configuration.companies[0].maxMorons << std::endl;


    const int MSG_TAG = 0;
    if (rank == 0) {
        MessageRequest message(1410, 1);
        std::stringstream serializedMessage = Serializer::serialize(message);
        Messanger::sendToAll(serializedMessage, MSG_TAG);
    } else {
        std::stringstream serializedMessage = Messanger::receiveFromAny(MSG_TAG);
        MessageRequest message;
        Serializer::deserialize(message, serializedMessage);
        std::cout << "Hello from thread " << rank << " message request timestamp: " << message.timestamp
                  << " | company id:" << message.companyId << "\n";
    }

    Agent agent(rank, agentsNumber, configuration);
//    agent.run();

    MPI_Finalize();
    return 0;
}