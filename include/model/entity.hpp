#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/entity/entityType.hpp"

class Entity {
private: 
    int x;
    int y;
public: 
    Entity(int x, int y): x(x), y(y) { }
    virtual ~Entity();

    virtual int getId() const = 0;
    int getX() const;
    int getY() const;
    virtual bool isPushable() const = 0;
    virtual bool isStackable() const = 0;
};

#endif