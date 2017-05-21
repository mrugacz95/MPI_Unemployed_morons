//
// Created by mrugi on 20.05.17.
//
#include <fstream>
#include "Configuration.h"
int Configuration::initMoronsNumber = -1;
int Configuration::N = -1;
void Configuration::loadConfiguration() {

    std::ifstream i("config.json");
    json j;
    i >> j;
    for(json::iterator it = j["companies"].begin(); it != j["companies"].end(); it++){
        json jsonCompany = it.value();
        Company c(jsonCompany);
        std::cout<<"max dmg lvl from json "<<c.maxDamageLevel<<"\n";
    }
}

int Configuration::getInitMoronsNumber() {
    return Configuration::initMoronsNumber;
}
