#include "model/entity.hpp"

Entity::~Entity() {}

int Entity::getId() const {
    return id;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

bool Entity::isNounText() const {
    return id >= static_cast<int>(NounText::TEXTBABA) && 
           id <= static_cast<int>(NounText::TEXTWALL);
}

bool Entity::isOperatorText() const {
    return id == static_cast<int>(OperatorText::TEXTIS);
}

bool Entity::isPropertyText() const {
    return id >= static_cast<int>(PropertyText::TEXTYOU) && 
           id <= static_cast<int>(PropertyText::TEXTSTOP);
}

NounText Entity::getNounText() const {
    return static_cast<NounText>(id);
}

OperatorText Entity::getOperatorText() const {
    return static_cast<OperatorText>(id);
}

PropertyText Entity::getPropertyText() const {
    return static_cast<PropertyText>(id);
}