#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(Position pos, int id);

    OperatorWordEntity getOperatorWordEntity() const;
};

#endif