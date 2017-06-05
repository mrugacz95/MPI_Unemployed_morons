/* C Example */
#include <fstream>
#include "cereal/archives/json.hpp"

#include <mpi.h>
#include "domain/Agent.h"
#include "MPIUtils/Messanger.h"


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


    if (rank == 0) {
        std::stringstream message;
        Configuration::Company company;
        company.maxDamageLevel =88;
        company.maxMorons = 66;
        {
            cereal::JSONOutputArchive json(message);
            json(company);
        }
        Messanger::sendToAll(message, 0);
    } else {
        std::stringstream receivedStream = Messanger::receiveFromAny(0);
        cereal::JSONInputArchive inJson(receivedStream);
        Configuration::Company comp;
        inJson(comp);
        std::cout << "Message recevied :" << rank << "  " << comp.maxMorons << " " << comp.maxDamageLevel <<"\n";
    }

    Agent agent(rank, agentsNumber, configuration);
    agent.run();

    MPI_Finalize();
    return 0;
}