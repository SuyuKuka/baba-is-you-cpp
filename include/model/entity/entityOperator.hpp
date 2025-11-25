#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    OperatorWordEntity getOperatorWordEntity() const {
        return static_cast<OperatorWordEntity>(getId());
    }
};

#endif