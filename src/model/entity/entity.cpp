#include "model/entity/entity.hpp"

Entity::~Entity() {}

int Entity::getId() const {
    return id;
}

bool Entity::isPushable() const {
    return true;
}

void Entity::setPushable(bool pushable) {
    (void)pushable;
}

bool Entity::isPullable() const {
    return true;
}

void Entity::setPullable(const bool pullable) {
    (void) pullable;
}

bool Entity::isNounWordEntity() const {
    return id >= static_cast<int>(NounWordEntity::TEXTBABA) && 
           id <= 299;
}

bool Entity::isOperatorWordEntity() const {
    return id >= static_cast<int>(OperatorWordEntity::TEXTIS) &&
           id <= 399;
}

bool Entity::isPropertyWordEntity() const {
    return id >= static_cast<int>(PropertyWordEntity::TEXTYOU) && 
           id <= 499;
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