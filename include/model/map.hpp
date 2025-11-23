#ifndef _MAP
#define _MAP
#include <iostream>
#include <vector>
#include "model/cell.hpp"
using namespace std;

class Map {
private: 
    int width;
    int height;
    vector<vector<Cell>> map;
    friend class MapParser;
public: 
    Map(int width, int height): width(width), height(height) {
        map.resize(height, vector<Cell>(width));
    }

    void addCell(int x, int y, Entity* entity);
    void printMap();

    /**
     * @brief Cette fonction crée une copie.
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;

};

#endif