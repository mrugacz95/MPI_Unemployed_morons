//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_COMPANY_H
#define MPI_UNEMPLOYED_MORONS_COMPANY_H


#include "AgentOnQueue.h"
#include <queue>
#include <memory>

class Company {
public:
    Company(int maxMorons, int maxDamageLevel);

    int moronsNumber;
    int maxDamageLevel;
    int id;
    int damageLevel = 0;
    int maxMorons;
    std::priority_queue<AgentOnQueue> waitingQueue;
    int timestamp;
    struct DataToSend {
    };

    DataToSend getDataToSend();
};

typedef std::shared_ptr<Company> CompanyRef;

#endif //MPI_UNEMPLOYED_MORONS_COMPANY_H
