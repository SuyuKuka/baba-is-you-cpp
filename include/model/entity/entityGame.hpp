#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityGame: public Entity {
private:
    bool pushable;
public:
    EntityGame(Position pos, int id): Entity(pos, id) {
        pushable = false;
    }

    bool isPushable() const override {
        return pushable;
    }

    void reversePushable() override {
        pushable = !pushable;
    }

    GameEntity getGameEntity() const override {
        return static_cast<GameEntity>(getId());
    }
};

#endif