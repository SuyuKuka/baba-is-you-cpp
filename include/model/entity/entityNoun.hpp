#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityNoun: public Entity {
public:
    EntityNoun(Position pos, int id): Entity(pos, id) { }

    bool isPushable() const override {
        return true;
    }

    void setPushable(bool pushable) {
        (void)pushable;
    }

    NounWordEntity getNounWordEntity() const {
        return static_cast<NounWordEntity>(getId());
    }

    bool isPullable() const override { return true; }
};

#endif