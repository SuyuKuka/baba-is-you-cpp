#ifndef MAIN_MODEL_HPP
#define MAIN_MODEL_HPP
#include "model/map/map.hpp"
#include "model/map/mapParser.hpp"
#include "model/map/undoRedoHandler.hpp"
using namespace std;

class Map;
class RuleEngine;
class RuleProcessor;

class MainModel {
private:
    Map* map;
    RuleEngine* rules;
    RuleProcessor* ruleProcessor;
    UndoRedoHandler undoRedoHandler;
    bool win = false;
public:
    MainModel();
    ~MainModel();

    void init(Map* map);
    void update(const Position& dPos, const bool& isPulling, const Direction& lastDirection);
    void move(const Position& dPos, const bool& isPulling);
    void applyPush(const Position& pos, Position& newPos, const Position& dPos, const vector<int> stopId, bool& move);
    void applyTransformations(const Rule& rule);
    void applyOpen(Position newPos, const Position& dPos, vector<int>& openId, vector<int>& shutId);
    void applyPull(const Position& pullPos, const Position& newPos);
    Direction undo();
    Direction redo();
    void undoNext();
    RuleEngine &getRuleEngine() const { return *rules; }
    RuleProcessor& getRuleProcessor() const { return *ruleProcessor; }
    Map* getMap() const { return map; }
    bool isWin() const { return win; }
    UndoRedoHandler getUndoRedoHandler() const;
};

#endif