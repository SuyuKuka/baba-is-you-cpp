#include "model/entity/entityOperator.hpp"

bool EntityOperator::isPushable() const {
    return false;
}

bool EntityOperator::isStackable() const {
    return false;
}

OperatorType EntityOperator::getOperatorType() const {
    return static_cast<OperatorType>(getId() - 9);
}