//
// Created by tommy on 05.06.17.
//

#include "Message.h"

Message::Message(int timestamp, Message::MESSAGE_TYPE type) {
    this->timestamp = timestamp;
    this->type = type;
}
