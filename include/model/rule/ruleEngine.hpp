#ifndef RULE_ENGINE_HPP
#define RULE_ENGINE_HPP
#include "model/rule/rule.hpp"
using namespace std;

class Map;

class RuleEngine {
private:
    Map& map;
    vector<Rule> activeRules;
public:
    RuleEngine(Map& map): map(map) {};

    void addActiveRule(NounWordEntity noun, OperatorWordEntity ope, PropertyWordEntity property, NounWordEntity transform);
    vector<Rule> getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;

    void updateRules();
    void checkRule(int x, int y, Entity* nounEntity, bool horizontal);
};

#endif