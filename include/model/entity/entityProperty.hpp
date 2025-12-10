#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity/entity.hpp"

class EntityProperty: public Entity {
public:
    EntityProperty(Position pos, int id);
    
    PropertyWordEntity getPropertyWordEntity() const;
};

#endif