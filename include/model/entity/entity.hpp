#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/map/position.hpp"
#include "model/entity/entityType.hpp"

class Entity {
private:
    Position pos; 
    int id;
public: 
    Entity(Position pos, int id) : pos(pos), id(id) { }
    virtual ~Entity();
    Position getPosition() const { return this->pos; };
    int getId() const;
    virtual bool isPushable() const;
    void setPosition(const Position& pos) { this->pos = pos; };
    void setId(int id) { this->id = id; };
    virtual void setPushable(bool pushable);
    bool isNounWordEntity() const;
    bool isOperatorWordEntity() const;
    bool isPropertyWordEntity() const;
    virtual GameEntity getGameEntity() const;
    virtual NounWordEntity getNounWordEntity() const;
    virtual OperatorWordEntity getOperatorWordEntity() const;
    virtual PropertyWordEntity getPropertyWordEntity() const;
};

#endif