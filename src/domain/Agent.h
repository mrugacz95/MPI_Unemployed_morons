//
// Created by mrugi on 21.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_AGENT_H
#define MPI_UNEMPLOYED_MORONS_AGENT_H


#include "MessageRequest.h"
#include "Configuration.h"
#include "Company.h"

class Agent {
private:
    int timestamp = 0;
    int initialNumberOfMorons;
    int numberOfMoronsToDispose;
    int rank;
    int agentsNumber;
    std::vector<CompanyRef> companies;

    void DisposeMorons();

    MessageRequest *receiveFromAny(MessageRequest *pMessage);

    void HandleRequest(MessageRequest *message);

    void initFromConfiguration(Configuration configuration);

public:
    Agent(int rank, int agentsNumber, Configuration configuration);

    void run();

    int getLastSender();

    void assignNewMorons();
};


#endif //MPI_UNEMPLOYED_MORONS_AGENT_H
