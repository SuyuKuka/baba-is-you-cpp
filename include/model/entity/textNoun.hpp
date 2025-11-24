#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity.hpp"

class TextNoun: public Entity {
public:
    TextNoun(int x, int y, int id): Entity(id, x, y) { }

    bool isPushable() const override {
        return true;
    }

    bool isStackable() const override {
        return false;
    }

    NounType getNounType() const override {
        return NounType::NONE;
    }
};

#endif