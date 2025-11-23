#ifndef ENTITY_PROPERTY_HPP
#define ENTITY_PROPERTY_HPP
#include "model/entity.hpp"

class EntityProperty: public Entity {
private:
    PropertyType type;
public:
    EntityProperty(int x, int y, PropertyType type) : Entity(x,y), type(type) { }

    int getId() const override {
        return static_cast<int>(type);
    }
};

#endif