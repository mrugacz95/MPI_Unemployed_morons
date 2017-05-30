//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
#define MPI_UNEMPLOYED_MORONS_CONFIGURATION_H

#include "../libs/json.hpp"
#include "Company.h"
#include "Companies.h"

using json = nlohmann::json;

class Configuration {
public:
    static Companies getCompanies();
    static int getInitialMoronsNumberPerAgent();
    static void setInitialMoronsNumberPerAgent(int initialMoronsNumberPerAgent);
private:
    static Companies companies;
    static int initialMoronsNumberPerAgent;
};

#endif //MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
