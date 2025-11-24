#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity.hpp"

class TextProperty: public Entity {
public:
    TextProperty(int x, int y, int id): Entity(id, x, y) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    PropertyType getPropertyType() const override {
        return PropertyType::NONE;
    }
};

#endif