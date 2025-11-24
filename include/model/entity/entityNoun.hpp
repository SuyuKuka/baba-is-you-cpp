#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity.hpp"

class EntityNoun: public Entity {
public:
    EntityNoun(int x, int y, int id): Entity(id, x, y) { }

    bool isPushable() const override;
    bool isStackable() const override;
    NounType getNounType() const override;
};

#endif