#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/entity/entityType.hpp"

class Entity {
    private:
    int x;
    int y; 
    public: 
    Entity(const int x, const int y) : x(x), y(y) { }
    const int& getX() const;
    const int& getY() const;

    virtual int getId() const = 0;
};

#endif