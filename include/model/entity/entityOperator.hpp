#ifndef ENTITY_OPERATOR_HPP
#define ENTITY_OPERATOR_HPP
#include "model/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(int x, int y, int id): Entity(id, x, y) { }

    bool isPushable() const override;
    bool isStackable() const override;
    OperatorType getOperatorType() const override;
};

#endif