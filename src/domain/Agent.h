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
    int initialNumberOfMorons;
    int numberOfMoronsToDispose;
    int rank;
    int agentsNumber;
    std::vector<Company> companies;

    void DisposeMorons();

    void SendRequest(MessageRequest *message);

    void initFromConfiguration(Configuration configuration);

public:
    Agent(int rank, int agentsNumber, Configuration configuration);

    void run();


    void assignNewMorons();

    int timestamp = 0;

    void requestAllComapnies();

    void addToWaitingQueue(int companyId, AgentOnQueue &agent);
};


#endif //MPI_UNEMPLOYED_MORONS_AGENT_H
