#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity.hpp"

class TextOperator: public Entity {
private:
    OperatorText type;
public:
    TextOperator(int x, int y, OperatorText type): Entity(x, y), type(type) { }

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