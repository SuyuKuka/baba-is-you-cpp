#include "model/map/map.hpp"

Map::Map(int width, int height): width(width), height(height) {
    map.resize(height, vector<Cell>(width));
}

Map::~Map() {
    for (vector<Cell>& list : map) {
        for (Cell& cell : list) {
            cell.deleteEntities();
        }
    }
}

Cell& Map::operator[](const Position& pos) {
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height) {
        throw out_of_range("Index out of range");
    }
    return map[pos.y][pos.x]; 
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

const vector<vector<Cell>>& Map::getMap() const { 
    return map; 
}

const vector<Entity*>& Map::getNounsEntityOnMap() const { 
    return nounsEntityOnMap; 
}

const vector<Entity*>& Map::getNounsTextOnMap() const { 
    return nounsTextOnMap; 
}

void Map::addCell(Position pos, Entity* entity) {
    (*this)[pos].addEntity(entity);
}

void Map::removeCell(Position pos, Entity* entity) {
    (*this)[pos].removeEntity(entity);
}

void Map::deleteCell(Position pos, Entity* entity) {
    (*this)[pos].removeEntity(entity);
    nounsEntityOnMap.erase(remove(nounsEntityOnMap.begin(), nounsEntityOnMap.end(), entity), nounsEntityOnMap.end());
}

void Map::addNounTextOnMap(Entity* noun) {
    nounsTextOnMap.push_back(noun);
}

void Map::addNounEntityOnMap(Entity* noun) {
    nounsEntityOnMap.push_back(noun);
}

const vector<const Cell*> Map::getOccupiedCells() const {
    occupiedCells.clear();
    occupiedCells.clear();
    for (const vector<Cell>& vCell : map) {
        for(const Cell& cell : vCell) {
            if (!cell.getEntities().empty()) {
                occupiedCells.push_back(&cell);
                occupiedCells.push_back(&cell);
            }
        }
    }
    return occupiedCells;
}