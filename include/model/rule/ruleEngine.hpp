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

    void addActiveRule(const NounWordEntity noun, const OperatorWordEntity ope, const PropertyWordEntity property, const NounWordEntity transform);
    const vector<Rule>& getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;

    void updateRules();
    void checkRules(Position pos, const Entity* nounEntity, const bool horizontal);
};

#endif