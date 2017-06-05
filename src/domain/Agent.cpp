//
// Created by mrugi on 21.05.17.
//

#include <mpi.h>
#include "Agent.h"
#include "Configuration.h"

Agent::Agent(int rank, int agentsNumber, Configuration configuration) {
    this->rank = rank;
    this->agentsNumber = agentsNumber;
    this->initFromConfiguration(configuration);
}

void Agent::initFromConfiguration(Configuration configuration) {
    this->initialNumberOfMorons = configuration.initialMoronsNumberPerAgent;
    for(Configuration::Company company : configuration.companies){
        CompanyRef currentCompany = CompanyRef(new Company(company));
        companies.push_back(currentCompany);
    }
}



void Agent::run() {
    assignNewMorons();
    MessageRequest request{MessageRequest::REQUEST, 0, this->timestamp};

    DisposeMorons();
}

void Agent::assignNewMorons() {
    numberOfMoronsToDispose = this->initialNumberOfMorons;
}

void Agent::DisposeMorons() {
    while (numberOfMoronsToDispose > 0) {
        MessageRequest message;
//        receiveFromAny(&message);
//        if (message.type == MessageRequest::REQUEST) {
//            HandleRequest(&message);
//        }
//        else if(message.type == MessageRequest::REPLAY){
//            //add to queue before me
//        }

    }
}

MessageRequest *Agent::receiveFromAny(MessageRequest *message) {
    MPI_Recv(&message, 3, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    timestamp = std::max(timestamp, message->timestamp) + 1;
    return message;
}

void Agent::HandleRequest(MessageRequest *message) {
    int sender_rank = getLastSender();
    if (message->timestamp < timestamp or message->timestamp == timestamp and sender_rank < rank){
        //allow

    }
    else {
        //add to queue
    }

}

int Agent::getLastSender() {
    MPI_Status status;
    int count;
    MPI_Get_count(&status, MPI_INT, &count);
    return status.MPI_SOURCE;
}
