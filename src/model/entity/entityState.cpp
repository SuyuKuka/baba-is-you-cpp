#include "model/entity/entityState.hpp"

EntityState::EntityState() = default;

EntityState::EntityState(Entity* pEntity, Position position, int id) : pEntity(pEntity), posBefore(position), idBefore(id) { 
    posAfter = Position(0,0);
    idAfter = 0;
}

EntityState::~EntityState() = default;

void EntityState::loadBeforeState() { 
    posAfter = pEntity -> getPosition();
    idAfter = pEntity -> getId();
    pEntity -> setId(idBefore);
    pEntity -> setPosition(posBefore);
}

void EntityState::loadAfterState() {
    pEntity -> setPosition(posAfter);
    pEntity -> setId(idAfter);
}

Entity* EntityState::getEntity() const {
    return pEntity;
}

Position EntityState::getPosBefore() const {
    return posBefore;
}

Position EntityState::getPosAfter() const {
    return posAfter;
}

int EntityState::getIdBefore() const {
    return idBefore;
}

int EntityState::getIdAfter() const {
    return idAfter;
}