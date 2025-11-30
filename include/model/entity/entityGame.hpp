#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityGame: public Entity {
public:
    EntityGame(Position pos, int id): Entity(pos, id, false, false) { }

    GameEntity getGameEntity() const override {
        return static_cast<GameEntity>(getId());
    }
};

#endif