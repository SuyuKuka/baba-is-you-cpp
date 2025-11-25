#ifndef ENTITY_PROPERTY_HPP
#define ENTITY_PROPERTY_HPP
#include "model/entity.hpp"

class EntityProperty: public Entity {
public:
    EntityProperty(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override;
    bool isStackable() const override;
};

#endif