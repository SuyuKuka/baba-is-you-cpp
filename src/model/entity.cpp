#include "model/entity.hpp"

Entity::~Entity() {}

bool Entity::isPushable() const {
    return false;
}