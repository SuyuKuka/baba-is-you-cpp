#ifndef RULE_PROCESSOR_HPP
#define RULE_PROCESSOR_HPP
#include <iostream>
#include <vector>
#include "model/rule/rule.hpp"
#include "model/entity/entity.hpp"
#include "model/entity/entityType.hpp"
#include "model/entity/entityType.hpp"
using namespace std;

class Map;

class RuleProcessor{
private:
    Map& map;
    mutable vector<int> youId;
public:
    RuleProcessor(Map& map): map(map) {}
    ~RuleProcessor() = default;

    void initIds(vector<int>& stopId, vector<int>& winId, vector<int>& openId, vector<int>& shutId) const;
    const vector<Entity*> isYou() const;
    bool isStop(const Position& newPos, const vector<int>& stopId) const;
    bool isNextPushable(const Position& newPos) const;
    void updatePullable(const Position& pullPos) const;
    bool isWin(const Position& newPos, const vector<int>& winId) const;
    const vector<Rule> isTransformation();
    bool isOpen(const Position newPos, const Position& dPos, const vector<int>& openId, const vector<int>& shutId) const;
    const vector<int>& getYouID() const { return youId; }
    bool babaIsYou() const;
};



#endif