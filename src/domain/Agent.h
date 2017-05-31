//
// Created by mrugi on 21.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_AGENT_H
#define MPI_UNEMPLOYED_MORONS_AGENT_H


#include "Message.h"

class Agent {
private:
    int timestamp;
    int numberOfMoronsToDispose;
    int rank;
    int agentsNumber;

    void SendToAll(Message *message);

    void DisposeMorons();

    Message *receiveFromAny(Message *pMessage);

    void HandleRequest(Message *message);

public:
    Agent(int rank, int agentsNumber);

    void run();

    int getLastSender();

    void assignNewMorons();
};


#endif //MPI_UNEMPLOYED_MORONS_AGENT_H
