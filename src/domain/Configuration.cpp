//
// Created by mrugi on 20.05.17.
//
#include "Configuration.h"
int Configuration::initialMoronsNumberPerAgent = -1;
Companies Configuration::companies;

int Configuration::getInitialMoronsNumberPerAgent() {
    return Configuration::initialMoronsNumberPerAgent;
}

Companies Configuration::getCompanies() {
    return Configuration::companies;
}

void Configuration::setInitialMoronsNumberPerAgent(int initialMoronsNumberPerAgent) {
    Configuration::initialMoronsNumberPerAgent = initialMoronsNumberPerAgent;
}
