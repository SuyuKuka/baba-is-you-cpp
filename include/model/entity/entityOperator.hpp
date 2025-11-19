#ifndef ENTITY_OPERATOR_HPP
#define ENTITY_OPERATOR_HPP
#include "model/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(int x, int y) : Entity(x, y) {}
};

#endif