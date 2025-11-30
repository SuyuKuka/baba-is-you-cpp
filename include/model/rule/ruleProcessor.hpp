#ifndef RULE_PROCESSOR_HPP
#define RULE_PROCESSOR_HPP
#include <iostream>
#include <vector>
#include "model/rule/rule.hpp"
#include "model/entity/entity.hpp"
using namespace std;

class Map;

class RuleProcessor{
private:
    Map& map;
public:
    RuleProcessor(Map& map): map(map) {}
    ~RuleProcessor() = default;

    void initIds(vector<int>& youId, vector<int>& stopId, vector<int>& winId) const;
    const vector<Entity*> isYou(const vector<int> youId);
    bool isStop(const Position& newPos, const vector<int>& stopId) const;
    bool isNextPushable(const Position& newPos) const;
    bool isWin(const Position& newPos, const vector<int>& winId) const;
    const vector<Rule> isTransformation();
};

#endif