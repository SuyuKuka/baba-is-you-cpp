#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <vector>
#include "model/map/cell.hpp"
#include "model/rule/ruleEngine.hpp"
using namespace std;

class RuleEngine;

class Map {
private: 
    int width;
    int height;
    vector<vector<Cell>> map;
    vector<Entity*> nounsTextOnMap;
    vector<Entity*> nounsEntityOnMap;
    RuleEngine rules;
    friend class MapParser;
public: 
    Map(int width, int height);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    vector<vector<Cell>> getMap() const { return map; }
    vector<Entity*> getNounsTextOnMap() const { return nounsTextOnMap; }

    void addCell(int x, int y, Entity* entity);
    void addNounTextOnMap(Entity* entity);
    void addNounEntityOnMap(Entity* entity);
    void removeCell(int x, int y, Entity* entity);
    const Cell& getCell(int x, int y) const;
    RuleEngine& getRuleEngine() { return rules; }
    void initIds(vector<int>& youId, vector<int>& stopId, vector<int>& winId);
    void move(const int dx, const int dy);
    void executePush(const int x, const int y, int& newX, int& newY, const int dx, const int dy);
    bool isStop(const int newX, const int newY, const vector<int> stop) const;
    bool isPushable(const int newX, const int newY) const;
    void clear();

    /**
     * @brief Cette fonction crée une copie.
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;

};

#endif