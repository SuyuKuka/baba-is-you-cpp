#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity.hpp"

class TextOperator: public Entity {
public:
    TextOperator(int x, int y, int id): Entity(id, x, y) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    OperatorType getOperatorType() const override {
        return OperatorType::NONE;
    }
};

#endif