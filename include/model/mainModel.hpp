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
    void move(const Position& dPos, const bool& isPulling, const Direction& lastDirection);
    void checkMove(vector<Entity*>& entities, const Position& dPos, const bool& isPulling, const Direction& lastDirection, bool& move, bool& oneWasMoved);
    void applyMove(Entity* entity, const Position& pos, const Position& newPos, bool& oneWasMoved);
    void applyPush(const Position& pos, Position& newPos, const Position& dPos, bool& move);
    void findLastPushable(Position& newPos, const Position& dPos, bool& move);
    void applyTransformations(const Rule& rule);
    void applyOpen(Position newPos, const Position& dPos);
    void removeEntity(const Position& pos, const std::vector<int>& targetIds);
    void applyPull(const Position& pullPos, const Position& newPos);
    Direction undo();
    Direction redo();
    Map* getMap() const;
    RuleEngine &getRuleEngine() const;
    RuleProcessor& getRuleProcessor() const;
    bool isWin() const;
};

#endif