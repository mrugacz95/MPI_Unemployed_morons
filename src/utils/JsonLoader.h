//
// Created by tommy on 30.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_JSONLOADER_H
#define MPI_UNEMPLOYED_MORONS_JSONLOADER_H

#include <string>
#include <fstream>
#include "../include/Json.h"

class JsonLoader {
public:
    static JsonRef loadJson(std::string path);
};


#endif //MPI_UNEMPLOYED_MORONS_JSONLOADER_H
