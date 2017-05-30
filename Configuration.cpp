//
// Created by mrugi on 20.05.17.
//
#include <fstream>
#include "Configuration.h"
int Configuration::agentsInitialMoronsNumber = -1;
int Configuration::numberOfAgents = -1;
void Configuration::loadConfiguration() {

    std::ifstream jsonStream("config.json");
    json configJson;
    jsonStream >> configJson;
    for(json::iterator it = configJson["companies"].begin(); it != configJson["companies"].end(); it++){
        json jsonCompany = it.value();
        Company c(jsonCompany);
        std::cout<<"max dmg lvl from json "<<c.maxDamageLevel<<"\n";
    }
}

int Configuration::getInitMoronsNumber() {
    return Configuration::agentsInitialMoronsNumber;
}
