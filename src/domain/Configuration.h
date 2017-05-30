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
    static int getInitialMoronsNumberPerAgent();
    static void setInitialMoronsNumberPerAgent(int initialMoronsNumberPerAgent);
    static void setCompanies(CompaniesRef companies);
private:
    static CompaniesRef companies;
    static int initialMoronsNumberPerAgent;
};

#endif //MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
