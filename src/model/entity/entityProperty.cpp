#include "model/entity/entityProperty.hpp"

bool EntityProperty::isPushable() const {
    return false;
}

bool EntityProperty::isStackable() const {
    return false;
}

PropertyType EntityProperty::getPropertyType() const {
    return static_cast<PropertyType>(getId() - 9);
}