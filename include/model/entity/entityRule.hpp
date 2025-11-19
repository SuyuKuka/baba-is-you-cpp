#ifndef ENTITY_RULE_HPP
#define ENTITY_RULE_HPP
#include "model/entity.hpp"

class EntityRule: public Entity {
public:
    EntityRule(int x, int y) : Entity(x, y) {}
};

#endif