#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/map/position.hpp"
#include "model/entity/entityType.hpp"

class Entity {
private:
    Position pos; 
    int id;
    bool pushable;
public: 
    Entity(Position pos, int id, bool pushable) : pos(pos), id(id), pushable(pushable) { }
    virtual ~Entity();
    Position getPosition() const { return this->pos; };
    int getId() const;
    bool isPushable() const { return this->pushable; };
    void setPosition(const Position& pos) { this->pos = pos; };
    void setId(int id) { this->id = id; };
    void setIsPushable(const bool pushable) { this->pushable = pushable; };
    bool isNounWordEntity() const;
    bool isOperatorWordEntity() const;
    bool isPropertyWordEntity() const;
    virtual GameEntity getGameEntity() const;
    virtual NounWordEntity getNounWordEntity() const;
    virtual OperatorWordEntity getOperatorWordEntity() const;
    virtual PropertyWordEntity getPropertyWordEntity() const;
};

#endif