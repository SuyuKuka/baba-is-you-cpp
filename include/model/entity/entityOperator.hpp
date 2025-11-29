#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity/entity.hpp"

class EntityOperator: public Entity {
public:
    EntityOperator(int x, int y, int id): Entity(x, y, id, true) { }

    OperatorWordEntity getOperatorWordEntity() const {
        return static_cast<OperatorWordEntity>(getId());
    }
};

#endif