#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"
#include "model/map/map.hpp"

class EntityGame: public Entity {
public:
    EntityGame(int x, int y, int id): Entity(x, y, id) { }

    GameEntity getGameEntity() const override {
        return static_cast<GameEntity>(getId());
    }
};

#endif