//
// Created by mrugi on 21.05.17.
//

#include <mpi.h>
#include "Agent.h"
#include "../MPIUtils/Messanger.h"
#include "../cerealUtils/Serializer.h"

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

void Agent::requestAllComapnies(){

    for (int i = 0; i < this->companies.size(); ++i) {
        MessageRequest message(timestamp, i);
        std::stringstream serializedMessage = Serializer::serialize(message);
        Messanger::sendToAll(serializedMessage, Message::MESSAGE_TYPE::REQUEST, this->timestamp);
    }
}

void Agent::DisposeMorons() {
    numberOfMoronsToDispose = initialNumberOfMorons;
    int ackCount = 0;
    while (numberOfMoronsToDispose > 0) {
        requestAllComapnies();
        int tag = Messanger::getNextTag();
        int sender = Messanger::getSender();
        std::stringstream receivedMessage = Messanger::receiveFromAny(tag);
        if(tag == Message::MESSAGE_TYPE::REQUEST){
            MessageRequest request;
            Serializer::deserialize(request, receivedMessage);
            addToWaitingQueue(0, <#initializer#>);
        } else if (tag == Message::MESSAGE_TYPE::REPLY) {
            ackCount++;
            MessageReply reply;
            Serializer::deserialize(reply, receivedMessage);
            //todo update copmany timestamp, morons, damage based on company_timestamp
            if(ackCount == agentsNumber){
                //todo dispose morons
            }
        }

    }
}

void Agent::SendRequest(MessageRequest *message) { //todo unused

}

void Agent::addToWaitingQueue(int companyId, AgentOnQueue &agent) {
    this->companies[companyId].get()->waitingQueue.push(agent);

}
