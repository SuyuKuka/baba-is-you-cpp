#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/entity/entityType.hpp"

class Entity {
private: 
    int x;
    int y;
    int id;
public: 
    Entity(int x, int y, int id): x(x), y(y), id(id) { }
    virtual ~Entity();

    int getId() const;
    int getX() const;
    int getY() const;
    virtual bool isPushable() const = 0;
    virtual bool isStackable() const = 0;
    bool isNounText() const;
    bool isOperatorText() const;
    bool isPropertyText() const;
    virtual NounType getNounType() const;
    virtual OperatorType getOperatorType() const;
    virtual PropertyType getPropertyType() const;
};

#endif