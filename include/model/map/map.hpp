#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <vector>
#include "model/map/cell.hpp"
#include "model/rule/ruleEngine.hpp"
#include "model/rule/ruleProcessor.hpp"
#include "model/entity/entity.hpp"
#include "model/map/position.hpp"
#include "model/entity/entityGame.hpp"
using namespace std;

class Map {
private: 
    int width;
    int height;
    vector<vector<Cell>> map;
    vector<Entity*> nounsTextOnMap;
    vector<Entity*> nounsEntityOnMap;
    friend class MapParser;
public: 
    Map(int width, int height);
    ~Map();
    Cell& operator[](const Position& pos);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const vector<vector<Cell>>& getMap() const { return map; }
    const vector<Entity*>& getNounsTextOnMap() const { return nounsTextOnMap; }
    void addCell(const Position pos, Entity* entity);
    void addNounTextOnMap(Entity* entity);
    void addNounEntityOnMap(Entity* entity);
    void removeCell(const Position pos, Entity* entity);
    void deleteCell(const Position pos, Entity* entity);
    vector<Entity*> getNounsEntityOnMap() const { return nounsEntityOnMap; }

    /**
     * @brief Cette fonction crée une copie.
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;
};

#endif