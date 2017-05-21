//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_COMPANY_H
#define MPI_UNEMPLOYED_MORONS_COMPANY_H


#include "AgentOnQueue.h"
#include <queue>

#include "json.hpp"

using json = nlohmann::json;

class Company {
public:
    Company(const json &j);

    int moronsNumber;
    int maxDamageLevel;
    int id;
    int damageLevel = 0;
    int maxMorons;
    std::priority_queue<AgentOnQueue> waitingQueue;
    int timestamp;
    typedef struct DataToSend {
    };

    DataToSend getDataToSend();

    void to_json(json &j, const Company &company);

    void from_json(const json &j);
};


#endif //MPI_UNEMPLOYED_MORONS_COMPANY_H
