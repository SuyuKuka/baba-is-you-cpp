#include "model/entity/entityOperator.hpp"

EntityOperator::EntityOperator(Position pos, int id): Entity(pos, id) { }

OperatorWordEntity EntityOperator::getOperatorWordEntity() const {
    return static_cast<OperatorWordEntity>(getId());
}