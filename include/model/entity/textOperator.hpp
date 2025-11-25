#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity.hpp"

class TextOperator: public Entity {
public:
    TextOperator(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    OperatorText getOperatorText() const {
        return static_cast<OperatorText>(getId());
    }
};

#endif