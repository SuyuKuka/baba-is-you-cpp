#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(Position pos, int id): Entity(pos, id) { }

    bool isPushable() const override {
        return true;
    }

    void setPushable(bool pushable) {
        (void)pushable;
    }

    OperatorWordEntity getOperatorWordEntity() const {
        return static_cast<OperatorWordEntity>(getId());
    }

    bool isPullable() const override { return true; }
};

#endif