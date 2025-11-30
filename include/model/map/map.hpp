#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <vector>
#include "model/map/cell.hpp"
#include "model/rule/ruleEngine.hpp"
#include "model/rule/ruleProcessor.hpp"
#include "model/entity/entityType.hpp"
#include "model/entity/entity.hpp"
#include "model/map/position.hpp"
using namespace std;

class RuleEngine;
class RuleProcessor;

class Map {
private: 
    int width;
    int height;
    vector<vector<Cell>> map;
    mutable vector<const Cell *> occupiedCells;
    vector<Entity*> nounsTextOnMap;
    vector<Entity*> nounsEntityOnMap;
    RuleEngine* rules = nullptr;
    RuleProcessor* ruleProcessor = nullptr;
    friend class MapParser;
public: 
    Map(int width, int height);
    ~Map();
    Cell& operator[](const Position& pos);
    const Cell& operator[](const Position& pos) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const vector<vector<Cell>>& getMap() const { return map; }
    const vector<Entity*>& getNounsTextOnMap() const { return nounsTextOnMap; }
    void addCell(const Position pos, Entity* entity);
    void addNounTextOnMap(Entity* entity);
    void addNounEntityOnMap(Entity* entity);
    void removeCell(const Position pos, Entity* entity);
    const vector<Entity*> getNounsEntityOnMap() const { return nounsEntityOnMap; }
    RuleEngine& getRuleEngine() const { return *rules; }
    RuleProcessor& getRuleProcessor() const { return *ruleProcessor; }
    void update(const Position dPos, const bool& pull);
    void move(const Position& dPos, const bool& pull);
    void applyPush(const Position& pos, Position& newPos, const Position& dPos, const vector<int> stopId, bool& move);
    void applyTransformations(const Rule& rule);
    void clear();

    /**
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;
};

#endif