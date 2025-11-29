#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity/entity.hpp"

class EntityProperty: public Entity {
public:
    EntityProperty(int x, int y, int id): Entity(x, y, id, true) { }

    PropertyWordEntity getPropertyWordEntity() const {
        return static_cast<PropertyWordEntity>(getId());
    }
};

#endif