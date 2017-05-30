//
// Created by tommy on 30.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_COMPANYJSONCONVERTER_H
#define MPI_UNEMPLOYED_MORONS_COMPANYJSONCONVERTER_H

#include "../include/Json.h"
#include "../domain/Company.h"

class CompanyJsonConverter {
public:
    static CompanyRef getFromJson(const JsonRef json);
    static JsonRef convertToJson(const CompanyRef company);
};


#endif //MPI_UNEMPLOYED_MORONS_COMPANYJSONCONVERTER_H
