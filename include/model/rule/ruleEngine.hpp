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
    ~RuleEngine() = default;

    void addActiveRule(NounWordEntity noun, OperatorWordEntity ope, PropertyWordEntity property, NounWordEntity transform);
    const vector<Rule> getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;

    void updateRules();
    void checkRules(const int x, const int y, const Entity* nounEntity, const bool horizontal);
};

#endif