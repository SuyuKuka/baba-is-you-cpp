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
    vector<Entity*> nouns;
    vector<Entity*> nounsEntityType;
    RuleEngine rules;
    friend class MapParser;
public: 
    Map(int width, int height);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    vector<vector<Cell>> getMap() const { return map; }
    vector<Entity*> getNouns() const { return nouns; }

    void addCell(int x, int y, Entity* entity);
    void addNoun(Entity* entity);
    void addNounEntityType(Entity* entity);
    void removeCell(int x, int y, Entity* entity);
    const Cell& getCell(int x, int y) const;
    RuleEngine& getRuleEngine() { return rules; }
    void clearNouns();
    void printMap();
    void printRules() const;
    void move(int dx, int dy);
    bool checkMove(int newX, int newY);
};

#endif