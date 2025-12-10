#ifndef _ENTITY_STATE
#define _ENTITY_STATE
#include <iostream>
#include "model/entity/entity.hpp"
#include "model/map/position.hpp"
using namespace std;

class EntityState {
private:
    Entity* pEntity;
    Position posBefore;
    Position posAfter;
    int idBefore;
    int idAfter;

public:
    EntityState();
    EntityState(Entity* pEntity, Position position, int id);
    ~EntityState();

    void loadBeforeState();
    void loadAfterState();
    Entity* getEntity() const;
    Position getPosBefore() const;
    Position getPosAfter() const;
    int getIdBefore() const;
    int getIdAfter() const;
}; 

#endif