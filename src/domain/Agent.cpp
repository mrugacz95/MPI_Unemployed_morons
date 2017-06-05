//
// Created by mrugi on 21.05.17.
//

#include <mpi.h>
#include "Agent.h"

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

    DisposeMorons();
}

void Agent::assignNewMorons() {
    numberOfMoronsToDispose = this->initialNumberOfMorons;
}

void Agent::DisposeMorons() {
    while (numberOfMoronsToDispose > 0) {
//        MessageRequest message;
//        std::stringstream message = Messanger::receiveFromAny(0);
//        if (message.type == MessageRequest::REQUEST) {
//            HandleRequest(&message);
//        }
//        else if(message.type == MessageRequest::REPLY){
//            //add to queue before me
//        }

    }
}

void Agent::HandleRequest(MessageRequest *message) {

}
