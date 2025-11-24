#include "model/entity/entityNoun.hpp"

bool EntityNoun::isPushable() const {
    return false;
}

bool EntityNoun::isStackable() const {
    return false;
}

NounType EntityNoun::getNounType() const {
    return static_cast<NounType>(getId() - 9);
}