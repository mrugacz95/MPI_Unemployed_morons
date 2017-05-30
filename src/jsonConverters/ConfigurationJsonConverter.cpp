//
// Created by tommy on 30.05.17.
//

#include "ConfigurationJsonConverter.h"
#include "CompanyJsonConverter.h"

void ConfigurationJsonConverter::getFromJson(const Json &json) {
    Configuration::setInitialMoronsNumberPerAgent(json.at("initialMoronsNumberPerAgent").get<int>());
    for(Json::const_iterator it = json["companies"].begin(); it != json["companies"].end(); it++){
        Json jsonCompany = it.value();
        CompanyRef company = CompanyJsonConverter::getCompanyFromJson(jsonCompany);
        Configuration::getCompanies().addCompany(company);
        std::cout<<"max dmg lvl from json "<<company->maxDamageLevel<<"\n";
    }
}
