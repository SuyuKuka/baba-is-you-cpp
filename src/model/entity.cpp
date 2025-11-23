#include "model/entity.hpp"

Entity::~Entity() {}

bool Entity::isPushable() const {
    return false;
}

const int& Entity::getX() const {
    return x;
}

const int& Entity::getY() const {
    return y;
}