#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityGame: public Entity {
private:
    bool pushable;
    bool pullable;
public:
    EntityGame(Position pos, int id): Entity(pos, id) {
        pushable = false;
        pullable = false;
    }

    bool isPushable() const override {
        return pushable;
    }

    void setPushable(bool pushable) override {
        this->pushable = pushable;
    }

    bool isPullable() const override {
        return pullable;
    }

    void setPullable(const bool pullable) override {
        this->pullable = pullable;
    }

    GameEntity getGameEntity() const override {
        return static_cast<GameEntity>(getId());
    }
};

#endif