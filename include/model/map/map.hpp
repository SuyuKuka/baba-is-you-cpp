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
#include "model/entity/entityGame.hpp"
using namespace std;

class Map {
private: 
    int width;
    int height;
    vector<vector<Cell>> map;
    mutable vector<const Cell *> occupiedCells;
    vector<Entity*> nounsTextOnMap;
    vector<Entity*> nounsEntityOnMap;
    friend class MapParser;

public: 
    Map(int width, int height);
    ~Map();
    Cell& operator[](const Position& pos);

    int getWidth() const;
    int getHeight() const;
    const vector<vector<Cell>>& getMap() const;
    const vector<Entity*>& getNounsEntityOnMap() const;
    const vector<Entity*>& getNounsTextOnMap() const;
    void addCell(const Position pos, Entity* entity);
    void addNounTextOnMap(Entity* entity);
    void addNounEntityOnMap(Entity* entity);
    void removeCell(const Position pos, Entity* entity);
    void deleteCell(const Position pos, Entity* entity);
    void clear();
    
    /**
     * @return Un vector contenant les cellules occupées.
     */
    const vector<const Cell*> getOccupiedCells() const;
};

#endif