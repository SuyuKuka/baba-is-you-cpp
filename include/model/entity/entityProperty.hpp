#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity/entity.hpp"

class EntityProperty: public Entity {
public:
    EntityProperty(Position pos, int id): Entity(pos, id) { }
    
    PropertyWordEntity getPropertyWordEntity() const {
        return static_cast<PropertyWordEntity>(getId());
    }
};

#endif