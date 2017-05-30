//
// Created by tommy on 30.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_COMPANYJSONCONVERTER_H
#define MPI_UNEMPLOYED_MORONS_COMPANYJSONCONVERTER_H

#include "../include/Json.h"
#include "../domain/Company.h"

class CompanyJsonConverter {
public:
    static CompanyRef getCompanyFromJson(const Json &json);
    static JsonRef convertCompanyToJson(const CompanyRef company);
};


#endif //MPI_UNEMPLOYED_MORONS_COMPANYJSONCONVERTER_H
