#ifndef RULE_PROCESSOR_HPP
#define RULE_PROCESSOR_HPP
#include <iostream>
#include <vector>
#include "model/rule/rule.hpp"
#include "model/entity/entity.hpp"
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

    void initIds(vector<int>& stopId, vector<int>& winId) const;
    const vector<Entity*> isYou() const;
    bool isStop(const int newX, const int newY, const vector<int> stopId) const;
    bool isNextPushable(const int newX, const int newY) const;
    bool isWin(const int newX, const int newY, const vector<int> winId) const;
    const vector<Rule> isTransformation();
    const vector<int>& getYouID() const { return youId; }
    bool babaIsYou() const;
};


#endif