#ifndef RULE_HPP
#define RULE_HPP
#include "model/entity/entityType.hpp"

class Rule {
private:
    int x;
    int y;
    NounText nounText;

public:
    Rule(int x, int y, NounText nounText) : x(x), y(y), nounText(nounText) {}
    int getX() const;
    int getY() const;
    NounText getNounText() const;
};

#endif