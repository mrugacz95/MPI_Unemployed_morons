//
// Created by tommy on 31.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_MESSANGER_H
#define MPI_UNEMPLOYED_MORONS_MESSANGER_H


class Messanger {
public:
    static void sendToAll(std::string serializedMessage, int msgTag);
};


#endif //MPI_UNEMPLOYED_MORONS_MESSANGER_H
