#ifndef _MAP
#define _MAP
#include <iostream>
#include <vector>
#include "model/cell.hpp"
#include "model/rule.hpp"
using namespace std;

class Map {
private: 
    int width;
    int height;
    vector<vector<Cell>> map;
    vector<Entity*> nouns;
    vector<Cell> nounsEntityType;
    Rule rules;
    friend class MapParser;
public: 
    Map(int width, int height): width(width), height(height) {
        map.resize(height, vector<Cell>(width));
    }

    void updateRules();
    void checkRule(int x, int y, Entity* nounEntity, bool horizontal);
    void addCell(int x, int y, Entity* entity);
    void addNoun(Entity* entity);
    void addNounEntityType(Entity* entity);
    void removeCell(int x, int y, Entity* entity);
    const Cell& getCell(int x, int y) const;
    const Rule& getRules() const;
    void clearNouns();
    void printMap();
    void printRules() const;
    void move(int dx, int dy);
};

#endif