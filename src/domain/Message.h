//
// Created by tommy on 05.06.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSAGE_H
#define MPI_UNEMPLOYED_MORONS_MESSAGE_H


class Message {
public:
    enum MESSAGE_TYPE {REQUEST, REPLAY};
    MESSAGE_TYPE type;
};


#endif //MPI_UNEMPLOYED_MORONS_MESSAGE_H
