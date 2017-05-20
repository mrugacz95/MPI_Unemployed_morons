//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_H

typedef struct Message {
    enum TYPE {REQUEST,REPLAY};
    TYPE type;
    int sender;
    int timestamp;
};
#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_H
