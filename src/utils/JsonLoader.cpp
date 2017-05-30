//
// Created by tommy on 30.05.17.
//

#include "JsonLoader.h"

JsonRef JsonLoader::loadJson(std::string path) {
    std::ifstream jsonStream(path);
    Json *configJson = new Json();
    jsonStream >> *configJson;
    return JsonRef(configJson);
}
