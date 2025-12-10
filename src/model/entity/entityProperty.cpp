#include "model/entity/entityProperty.hpp"

EntityProperty::EntityProperty(Position pos, int id): Entity(pos, id) { }

PropertyWordEntity EntityProperty::getPropertyWordEntity() const {
    return static_cast<PropertyWordEntity>(getId());
}