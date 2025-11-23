#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity.hpp"

class TextNoun: public Entity {
private:
    NounText type;
public:
    TextNoun(int x, int y, NounText type): Entity(x, y), type(type) { }

    int getId() const override {
        return static_cast<int>(type);
    }

    bool isPushable() const override {
        return true;
    }
};

#endif