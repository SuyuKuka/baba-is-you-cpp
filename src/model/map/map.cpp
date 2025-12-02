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
    vector<const Cell*> occupied;
    for (const vector<Cell>& vCell : map) {
        for(const Cell& cell : vCell) {
            if (!cell.getEntities().empty()) {
                occupied.push_back(&cell);
            }
        }
    }
    return occupied;
}
