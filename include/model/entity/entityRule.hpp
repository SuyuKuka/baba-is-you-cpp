#ifndef ENTITY_RULE_HPP
#define ENTITY_RULE_HPP
#include "model/entity.hpp"

class EntityRule: public Entity {
private:
    RuleType type;
public:
    EntityRule(int x, int y, RuleType type) : Entity(x,y), type(type) { }

    int getId() const override {
        return static_cast<int>(type);
    }
};

#endif