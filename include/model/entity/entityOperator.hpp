#ifndef ENTITY_OPERATOR_HPP
#define ENTITY_OPERATOR_HPP
#include "model/entity.hpp"

class EntityOperator: public Entity {
private:
    OperatorType type;
public:
    EntityOperator(OperatorType type) {
        this->type = type;
    }

    int getId() const override {
        return static_cast<int>(type);
    }
};

#endif