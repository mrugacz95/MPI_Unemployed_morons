//
// Created by mrugi on 21.05.17.
//

#include <mpi.h>
#include "Agent.h"
#include "Configuration.h"
#include "Message.h"

void Agent::SendToAll(Message *message) {
    timestamp++;
    MPI_Bcast(
            message,
            3,
            MPI_INT,
            0,
            MPI_Comm MPI_COMM_WORLD);
}

void Agent::run() {
    assignNewMorons();
    Message request{Message::REQUEST, 0, this->timestamp};
    SendToAll(&request);
    DisposeMorons();
}

void Agent::assignNewMorons() {
    numberOfMoronsToDispose = Configuration::getInitialMoronsNumberPerAgent();
}

void Agent::DisposeMorons() {
    while (numberOfMoronsToDispose > 0) {
        Message message;
        receiveFromAny(&message);
        if (message.type == Message::REQUEST) {
            HandleRequest(&message);
        }
        else if(message.type == Message::REPLAY){
            //add to queue before me
        }

    }
}

Message *Agent::receiveFromAny(Message *message) {
    MPI_Recv(&message, 3, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    timestamp = std::max(timestamp, message->timestamp) + 1;
    return message;
}

void Agent::HandleRequest(Message *message) {
    int sender_rank = getLastSender();
    if (message->timestamp < timestamp or message->timestamp == timestamp and sender_rank < rank){
        //allow

    }
    else {
        //add to queue
    }

}

Agent::Agent(int rank, int agentsNumber) {
    this->rank = rank;
    this->agentsNumber = agentsNumber;
}

int Agent::getLastSender() {
    MPI_Status status;
    int count;
    MPI_Get_count(&status, MPI_INT, &count);
    return status.MPI_SOURCE;
}
