#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity.hpp"
#include "model/entity/entityType.hpp"

class EntityNoun: public Entity {
private:
    NounType type;
public:
    EntityNoun(int x, int y, NounType type) : Entity(x, y) {
        this->type = type;
    }
};

#endif