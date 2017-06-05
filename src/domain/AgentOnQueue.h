//
// Created by mrugi on 20.05.17.
//

#ifndef MPI_UNEMPLOYED_MORONS_AGENTONQUEUE_H
#define MPI_UNEMPLOYED_MORONS_AGENTONQUEUE_H


class AgentOnQueue {
    int id;
    int timestamp;
public:
    AgentOnQueue(int id, int timestamp);

    bool operator<(AgentOnQueue rhs) const {
        return this->timestamp < rhs.timestamp;
    }
};


#endif //MPI_UNEMPLOYED_MORONS_AGENTONQUEUE_H
