//
// Created by tommy on 30.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_CONFIGURATIONJSONCONVERTER_H
#define MPI_UNEMPLOYED_MORONS_CONFIGURATIONJSONCONVERTER_H

#include "../include/Json.h"
#include "../domain/Configuration.h"

class ConfigurationJsonConverter {
public:
    static void getFromJson(const Json &json);
    static JsonRef convertToJson();
};


#endif //MPI_UNEMPLOYED_MORONS_CONFIGURATIONJSONCONVERTER_H
