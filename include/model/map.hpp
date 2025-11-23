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
    Rule rules;
    friend class MapParser;
public: 
    Map(int width, int height): width(width), height(height) {
        map.resize(height, vector<Cell>(width));
    }

    void addCell(int x, int y, Entity* entity);
    const Cell& getCell(int x, int y) const;
    const Rule& getRules() const;
    void printMap();
};

#endif