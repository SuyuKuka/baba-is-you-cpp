#ifndef ENTITY_PROPERTY_HPP
#define ENTITY_PROPERTY_HPP
#include "model/entity.hpp"

class EntityProperty: public Entity {
public:
    EntityProperty(int x, int y) : Entity(x, y) {}
};

#endif