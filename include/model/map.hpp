#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <vector>
#include "model/cell.hpp"
#include "model/ruleEngine.hpp"
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
    void printMap();
    void move(int dx, int dy);
    bool isStop(int newX, int newY, vector<int> stop);

    /**
     * @brief Cette fonction crée une copie.
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;

};

#endif