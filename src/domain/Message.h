//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_H


struct Message {
    enum TYPE {REQUEST,REPLAY};
    TYPE type;
    int companyId;
    int timestamp;
};
#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_H
