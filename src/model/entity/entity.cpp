#include "model/entity/entity.hpp"

Entity::~Entity() {}

int Entity::getId() const {
    return id;
}

bool Entity::isNounWordEntity() const {
    return id >= static_cast<int>(NounWordEntity::TEXTBABA) && 
           id <= static_cast<int>(NounWordEntity::TEXTWALL);
}

bool Entity::isOperatorWordEntity() const {
    return id == static_cast<int>(OperatorWordEntity::TEXTIS);
}

bool Entity::isPropertyWordEntity() const {
    return id >= static_cast<int>(PropertyWordEntity::TEXTYOU) && 
           id <= static_cast<int>(PropertyWordEntity::TEXTPULL);
}

GameEntity Entity::getGameEntity() const {
    return static_cast<GameEntity>(id);
}

NounWordEntity Entity::getNounWordEntity() const {
    return static_cast<NounWordEntity>(id);
}

OperatorWordEntity Entity::getOperatorWordEntity() const {
    return static_cast<OperatorWordEntity>(id);
}

PropertyWordEntity Entity::getPropertyWordEntity() const {
    return static_cast<PropertyWordEntity>(id);
}