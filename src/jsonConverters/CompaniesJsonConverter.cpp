//
// Created by tommy on 30.05.17.
//

#include "CompaniesJsonConverter.h"
#include "CompanyJsonConverter.h"

CompaniesRef CompaniesJsonConverter::getFromJson(const JsonRef json) {
    CompaniesRef companies(new Companies());
    for(Json::const_iterator it = json->begin(); it != json->end(); it++){
        JsonRef jsonCompany(new Json(it.value()));
        CompanyRef company = CompanyJsonConverter::getFromJson(jsonCompany);
        companies->addCompany(company);
        std::cout<<"max dmg lvl from json "<<company->maxDamageLevel<<"\n";
    }
    return companies;
}
