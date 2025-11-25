#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity.hpp"

class EntityGame: public Entity {
public:
    EntityGame(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override;
    bool isStackable() const override;
};

#endif