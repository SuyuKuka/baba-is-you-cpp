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
    vector<Entity*> entitiesNoun; // pour avoir la liste des entités qui sont deja utilisés dans les règles (jsp si utile pour le moment)
    vector<Entity*> entitiesOp;
    vector<Entity*> entitiesTarget;

public:
    RuleEngine(MainModel& game): game(game) { };
    ~RuleEngine() = default;

    void addActiveRule(const NounWordEntity noun, const OperatorWordEntity ope, const PropertyWordEntity property, const NounWordEntity transform);
    const vector<Rule>& getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;
    void updateRules();
    void checkRules(Position pos, Entity* nounEntity, const bool horizontal);
    void checking(Position& posOp, Position& posTarget, Cell& cellOp, Cell& cellTarget, int& dx, int& dy, bool& is);
    void addRules();
    void clear();
};

#endif