//
// Created by tommy on 30.05.17.
//

#include "CompanyJsonConverter.h"

CompanyRef CompanyJsonConverter::getFromJson(const JsonRef json) {
    int maxMorons = json->at("maxMorons").get<int>();
    int maxDamageLevel = json->at("maxDamageLevel").get<int>();

    return CompanyRef(new Company(maxMorons, maxDamageLevel));
}

JsonRef CompanyJsonConverter::convertToJson(const CompanyRef company) {
    JsonRef json(new Json{{"maxMorons",      company->maxMorons},
                          {"maxDamageLevel", company->maxDamageLevel}});
    return json;
}
