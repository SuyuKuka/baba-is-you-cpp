#ifndef _ENTITY_STATE
#define _ENTITY_STATE
#include <iostream>
#include "model/entity/entity.hpp"
#include "model/map/position.hpp"
using namespace std;

class EntityState {
    private:
    Entity * pEntity;
    Position posBefore;
    Position posAfter;
    int idBefore;
    int idAfter;
    public:
    EntityState() = default;
    EntityState(Entity * pEntity, Position position, int id) : pEntity(pEntity), posBefore(position), idBefore(id) { 
        posAfter = Position(0,0);
        idAfter = 0;
    }
    ~EntityState() = default;

    void loadBeforeState() { 
        posAfter = pEntity -> getPosition();
        idAfter = pEntity -> getId();
        pEntity -> setId(idBefore);
        pEntity -> setPosition(posBefore);
    }

    void loadAfterState() {
        pEntity -> setPosition(posAfter);
        pEntity -> setId(idAfter);
    }

    Entity* getEntity() const {
        return pEntity;
    }

    Position getPosBefore() const {
        return posBefore;
    }

    Position getPosAfter() const {
        return posAfter;
    }

    int getIdBefore() const {
        return idBefore;
    }

    int getIdAfter() const {
        return idAfter;
    }
}; 

#endif