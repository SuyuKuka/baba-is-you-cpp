#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/entity/entityType.hpp"

class Entity {
private:
    int x;
    int y; 
    int id;
public: 
    Entity(const int x, const int y, int id) : x(x), y(y), id(id) { }
    virtual ~Entity();
    const int& getX() const;
    const int& getY() const;
    int getId() const;
    void setX(int x) { this->x = x; };
    void setY(int y) { this->y = y; };
    void setId(int id) { this->id = id; };
    bool isNounWordEntity() const;
    bool isOperatorWordEntity() const;
    bool isPropertyWordEntity() const;
    virtual GameEntity getGameEntity() const;
    virtual NounWordEntity getNounWordEntity() const;
    virtual OperatorWordEntity getOperatorWordEntity() const;
    virtual PropertyWordEntity getPropertyWordEntity() const;
};

#endif