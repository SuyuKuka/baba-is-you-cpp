#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/entity/entityType.hpp"

class Entity {
private:
    int x;
    int y;
public: 
    Entity(int x, int y) : x(x), y(y) {}
};

#endif