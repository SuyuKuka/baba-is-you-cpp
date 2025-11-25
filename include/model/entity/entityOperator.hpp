#ifndef ENTITY_OPERATOR_HPP
#define ENTITY_OPERATOR_HPP
#include "model/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override;
    bool isStackable() const override;
};

#endif