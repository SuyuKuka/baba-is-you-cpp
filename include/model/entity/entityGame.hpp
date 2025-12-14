#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityGame: public Entity {
private:
    bool pushable;
    bool pullable;
    
public:
    EntityGame(Position pos, int id);

    bool isPushable() const override;
    void setPushable(bool pushable) override;
    bool isPullable() const override;
    void setPullable(const bool pullable) override;
    GameEntity getGameEntity() const override;
};

#endif