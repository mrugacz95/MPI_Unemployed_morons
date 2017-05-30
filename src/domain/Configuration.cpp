//
// Created by mrugi on 20.05.17.
//
#include "Configuration.h"
int Configuration::initialMoronsNumberPerAgent = -1;
CompaniesRef Configuration::companies;
int Configuration::getInitialMoronsNumberPerAgent() {
    return Configuration::initialMoronsNumberPerAgent;
}

void Configuration::setInitialMoronsNumberPerAgent(int initialMoronsNumberPerAgent) {
    Configuration::initialMoronsNumberPerAgent = initialMoronsNumberPerAgent;
}

void Configuration::setCompanies(CompaniesRef companies) {
    Configuration::companies = companies;
}
