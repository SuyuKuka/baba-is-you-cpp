#include "model/map.hpp"

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].addEntity(entity);
}

void Map::addRule(Rule noun) {
    rules.push_back(noun);
}

const Cell& Map::getCell(int x, int y) const {
    return map[y][x];
}

const vector<Rule>& Map::getRules() const {
    return rules;
}

void Map::printMap() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Cell& cell = map[y][x]; 
            
            if (!cell.isEmpty()) {
                Entity* entity = cell.getEntities()[0]; 
                int code = entity->getId();
                std::cout << code << " "; 
            } else {
                std::cout << "00 ";
            }
        }
        std::cout << std::endl;
    }
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
