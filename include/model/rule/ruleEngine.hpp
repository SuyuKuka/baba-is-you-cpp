#ifndef RULE_ENGINE_HPP
#define RULE_ENGINE_HPP
#include <vector>
#include "model/rule/rule.hpp"
#include "model/map/position.hpp"
#include "model/entity/entity.hpp"
#include "model/mainModel.hpp"
using namespace std;

class MainModel;

class RuleEngine {
private:
    MainModel& game;
    vector<Rule> activeRules;
public:
    RuleEngine(MainModel& game): game(game) {};
    ~RuleEngine() = default;

    void addActiveRule(const NounWordEntity noun, const OperatorWordEntity ope, const PropertyWordEntity property, const NounWordEntity transform);
    const vector<Rule>& getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;

    void updateRules();
    void checkRules(Position pos, const Entity* nounEntity, const bool horizontal);
};

#endif