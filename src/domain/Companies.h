//
// Created by tommy on 30.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_COMPANIES_H
#define MPI_UNEMPLOYED_MORONS_COMPANIES_H


#include "Company.h"

class Companies {
public:
    void addCompany(CompanyRef company);
private:
    std::vector<CompanyRef> companies;
};

typedef std::shared_ptr<Companies> CompaniesRef;

#endif //MPI_UNEMPLOYED_MORONS_COMPANIES_H
