#ifndef RULE_PROCESSOR_HPP
#define RULE_PROCESSOR_HPP
#include <iostream>
#include <vector>
#include "model/rule/rule.hpp"
#include "model/entity/entity.hpp"
#include "model/entity/entityType.hpp"
#include "model/entity/entityType.hpp"
using namespace std;

class MainModel;

class RuleProcessor{
private:
    MainModel& game;
    mutable vector<int> youId;
    mutable vector<int> stopId;
    mutable vector<int> winId;
    mutable vector<int> openId;
    mutable vector<int> shutId;

public:
    RuleProcessor(MainModel& game);
    ~RuleProcessor();

    void initIds();
    const vector<Entity*> isYou() const;
    bool isStop(const Position& newPos) const;
    bool isNextPushable(const Position& newPos) const;
    void updatePullable(const Position& pullPos) const;
    bool isWin(const Position& newPos) const;
    const vector<Rule> isTransformation();
    bool isOpen(const Position newPos, const Position& dPos) const;
    const vector<int>& getYouID() const;
    const vector<int>& getStopID() const;
    const vector<int>& getWinID() const;
    const vector<int>& getOpenID() const;
    const vector<int>& getShutID() const;
    bool babaIsYou() const;
    void clear();
};

#endif