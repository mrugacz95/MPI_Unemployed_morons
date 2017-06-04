//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
#define MPI_UNEMPLOYED_MORONS_CONFIGURATION_H

#include "cereal/archives/json.hpp"
#include "cereal/types/vector.hpp"

class Configuration {
public:
    class Company {
    public:
        int maxDamageLevel;
        int maxMorons;

        template<class Archive>
        void serialize(Archive &archive) {
            archive(CEREAL_NVP(maxDamageLevel), CEREAL_NVP(maxMorons));
        }
    };

    int initialMoronsNumberPerAgent;
    std::vector<Company> companies;

    template<class Archive>
    void serialize(Archive &archive) {
        archive(CEREAL_NVP(initialMoronsNumberPerAgent), CEREAL_NVP(companies));
    }
};

#endif //MPI_UNEMPLOYED_MORONS_CONFIGURATION_H
