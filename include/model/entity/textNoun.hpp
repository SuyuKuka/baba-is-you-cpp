#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity.hpp"

class TextNoun: public Entity {
public:
    TextNoun(int x, int y, int id): Entity(x, y, id) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    NounText getNounText() const {
        return static_cast<NounText>(getId());
    }
};

#endif