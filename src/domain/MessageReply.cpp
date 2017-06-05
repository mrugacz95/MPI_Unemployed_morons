//
// Created by tommy on 05.06.17.
//

#include "MessageReply.h"


MessageReply::MessageReply(Company &company, int agentTimestamp) : Message(agentTimestamp,
                                                                           Message::MESSAGE_TYPE::REPLY) {
    this->company.timestamp = company.timestamp;
    this->company.damage = company.damageLevel;
    this->company.morons = company.moronsNumber;
    this->company.id = company.id;
}