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

    /**
     * Met à jour les coordonnées actuelles dans les variables After.
     * Place l'entité dans sa précédente position.
     */
    void loadBeforeState();

    /**
     * Met à jour les coordonnées de l'entité à sa position After.
     * (Redo)
     */
    void loadAfterState();
    Entity* getEntity() const;
    Position getPosBefore() const;
    Position getPosAfter() const;
    int getIdBefore() const;
    int getIdAfter() const;
}; 

#endif