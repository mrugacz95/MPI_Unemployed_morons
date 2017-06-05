//
// Created by tommy on 05.06.17.
//

#include "MessageRequest.h"

MessageRequest::MessageRequest(int agentTimestamp, int companyId) : Message(agentTimestamp,
                                                                            Message::MESSAGE_TYPE::REQUEST) {
    this->companyId = companyId;
}
