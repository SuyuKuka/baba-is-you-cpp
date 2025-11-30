#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"
#include "model/map/map.hpp"

class EntityGame: public Entity {
public:
    EntityGame(Position pos, int id): Entity(pos, id, false) { }

    GameEntity getGameEntity() const override {
        return static_cast<GameEntity>(getId());
    }
};

#endif