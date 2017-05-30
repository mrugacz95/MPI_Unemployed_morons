//
// Created by tommy on 30.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_COMPANIESJSONCONVERTER_H
#define MPI_UNEMPLOYED_MORONS_COMPANIESJSONCONVERTER_H

#include "../include/Json.h"
#include "../domain/Companies.h"

class CompaniesJsonConverter {
public:
    static CompaniesRef getFromJson(const JsonRef json);
    JsonRef convertToJson(const CompaniesRef companies);
};


#endif //MPI_UNEMPLOYED_MORONS_COMPANIESJSONCONVERTER_H
