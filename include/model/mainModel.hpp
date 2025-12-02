#ifndef MAIN_MODEL_HPP
#define MAIN_MODEL_HPP
#include "model/map/map.hpp"
#include "model/map/mapParser.hpp"
using namespace std;

class Map;
class RuleEngine;
class RuleProcessor;

class MainModel {
private:
    Map* map;
    RuleEngine* rules;
    RuleProcessor* ruleProcessor;
    bool win = false;
public:
    MainModel();
    ~MainModel();

    void init(Map* map);
    void update(Position& dPos);
    void move(const Position& dPos);
    void applyPush(const Position& pos, Position& newPos, const Position& dPos, const vector<int> stopId, bool& move);
    void applyTransformations(const Rule& rule);
    void applyOpen(Position newPos, const Position& dPos, vector<int>& openId, vector<int>& shutId);
    RuleEngine& getRuleEngine() const { return *rules; }
    RuleProcessor& getRuleProcessor() const { return *ruleProcessor; }
    Map* getMap() const { return map; }
    bool isWin() const { return win; }
};

#endif