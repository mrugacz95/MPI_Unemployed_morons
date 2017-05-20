//
// Created by mrugi on 20.05.17.
//

#include "Company.h"
void Company::to_json(json &j, const Company &company) {
    j = json{{"maxMorons",      company.maxMorons},
             {"maxDamageLevel", company.maxDamageLevel}};
}

void Company::from_json(const json &j) {
    this->maxMorons = j.at("maxMorons").get<int>();
    this->maxDamageLevel = j.at("maxDamageLevel").get<int>();
}

Company::Company(const json &j) {
    from_json(j);
}
