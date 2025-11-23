#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity.hpp"
#include "entityType.hpp"

class EntityNoun: public Entity {
private:
    NounType type;
public:
    EntityNoun(int x, int y, NounType type): Entity(x, y), type(type) { }

    int getId() const override {
        return static_cast<int>(type);
    }

    bool isPushable() const override {
        return false;
    }
};

#endif