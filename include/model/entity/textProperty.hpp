#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity.hpp"

class TextProperty: public Entity {
private:
    PropertyText type;
public:
    TextProperty(int x, int y, PropertyText type): Entity(x, y), type(type) { }

    int getId() const override {
        return static_cast<int>(type);
    }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }
};

#endif