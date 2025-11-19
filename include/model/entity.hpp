#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "model/entity/entityType.hpp"

class Entity {
public: 
    Entity() {}

    virtual int getId() const = 0;
};

#endif