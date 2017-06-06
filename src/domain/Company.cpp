//
// Created by mrugi on 20.05.17.
//

#include "Company.h"

Company::Company(int maxMorons, int maxDamageLevel) {
    this->maxMorons = maxMorons;
    this->maxDamageLevel = maxDamageLevel;
}

Company::Company(Configuration::Company company) {
    this->maxMorons = company.maxMorons;
    this->maxDamageLevel = company.maxDamageLevel;
    this->timestamp = 0;
}
