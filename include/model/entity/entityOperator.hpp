#ifndef ENTITY_OPERATOR_HPP
#define ENTITY_OPERATOR_HPP
#include "model/entity.hpp"

class EntityOperator: public Entity {
private:
    OperatorType type;
public:
    EntityOperator(int x, int y, OperatorType type): Entity(x, y), type(type) { }

    int getId() const override {
        return static_cast<int>(type);
    }

    bool isPushable() const override {
        return false;
    }
};

#endif