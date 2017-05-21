//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
#define MPI_UNEMPLOYED_MORONS_CONFIGURATION_H

#include "json.hpp"
#include "Company.h"

using json = nlohmann::json;

class Configuration {
private:
    static int initMoronsNumber; //Agent initial morons number
    static int N;
public:
    static std::vector<Company> companies;

    static void loadConfiguration();

    static int getInitMoronsNumber();

};

#endif //MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
