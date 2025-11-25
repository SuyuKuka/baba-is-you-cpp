#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity.hpp"

class TextProperty: public Entity {
public:
    TextProperty(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    PropertyText getPropertyText() const {
        return static_cast<PropertyText>(getId());
    }
};

#endif