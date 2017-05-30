//
// Created by tommy on 30.05.17.
//

#include "ConfigurationJsonConverter.h"
#include "CompaniesJsonConverter.h"

void ConfigurationJsonConverter::getFromJson(const JsonRef json) {
    Configuration::setInitialMoronsNumberPerAgent(json->at("initialMoronsNumberPerAgent").get<int>());
    JsonRef jsonRef(new Json(json->at("companies")));
    Configuration::setCompanies(CompaniesJsonConverter::getFromJson(jsonRef));
}
