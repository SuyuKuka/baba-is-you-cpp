#ifndef ENTITY_PROPERTY_HPP
#define ENTITY_PROPERTY_HPP
#include "model/entity.hpp"

class EntityProperty: public Entity {
public:
    EntityProperty(int x, int y, int id): Entity(id, x, y) { }

    bool isPushable() const override;
    bool isStackable() const override;
    PropertyType getPropertyType() const override;
};

#endif