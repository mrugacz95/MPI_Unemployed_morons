//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
#define MPI_UNEMPLOYED_MORONS_CONFIGURATION_H

#include "json.hpp"
#include "Company.h"

using json = nlohmann::json;

class Configuration {
public:
    static const int D;
    static const int N;
    static std::vector<Company> companies;
    static void loadConfiguration();
};
#endif //MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
