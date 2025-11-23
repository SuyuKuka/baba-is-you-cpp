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
    vector<Rule> rules;
    friend class MapParser;
public: 
    Map(int width, int height): width(width), height(height) {
        map.resize(height, vector<Cell>(width));
    }

    void addCell(int x, int y, Entity* entity);
    void addRule(Rule rule);
    const Cell& getCell(int x, int y) const;
    const vector<Rule>& getRules() const;
    void printMap();

    /**
     * @brief Cette fonction crée une copie.
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;

};

#endif