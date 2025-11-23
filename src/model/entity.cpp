#include "model/entity.hpp"

Entity::~Entity() {}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

bool Entity::isPushable() const {
    return false;
}