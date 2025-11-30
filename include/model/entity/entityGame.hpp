#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityGame: public Entity {
private: 
bool pullable;
public:
    EntityGame(Position pos, int id): Entity(pos, id, false), pullable(false) { }

    GameEntity getGameEntity() const override {
        return static_cast<GameEntity>(getId());
    }

    const bool& isPullable() const override { return pullable; }
    void setIsPullable(const bool pullable) override { this->pullable = pullable; }
};

#endif