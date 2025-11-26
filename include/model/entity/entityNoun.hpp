#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity.hpp"
#include "entityType.hpp"

class EntityNoun: public Entity {
public:
    EntityNoun(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    bool isDestroyable() const override {
        return false;
    }

    NounWordEntity getNounWordEntity() const {
        return static_cast<NounWordEntity>(getId());
    }
};

#endif