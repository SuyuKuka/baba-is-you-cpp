#ifndef _MAP
#define _MAP
#include <iostream>
#include <vector>
#include "model/cell.hpp"
using namespace std;

class Map {
private: 
    int height;
    int width;
    vector<vector<Cell>> map;
    friend class MapParser;
public: 
    Map(int width, int height) : width(width), height(height) {
        map.resize(height, vector<Cell>(width));
    }

    void addCell(int x, int y, Entity* entity);
};

#endif