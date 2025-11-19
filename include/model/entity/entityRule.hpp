#ifndef ENTITY_RULE_HPP
#define ENTITY_RULE_HPP
#include "model/entity.hpp"

class EntityRule: public Entity {
private:
    RuleType type;
public:
    EntityRule(RuleType type) {
        this->type = type;
    }

    int getId() const override {
        return static_cast<int>(type);
    }
};

#endif