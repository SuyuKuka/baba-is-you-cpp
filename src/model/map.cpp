#include "model/map.hpp"

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].entities.push_back(entity);
}

void Map::printMap() {
    for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
        Cell& cell = map[y][x]; 
        
        if (!cell.entities.empty()) {
            Entity* entity = cell.entities[0]; 
            int code = entity->getId();
            std::cout << code << " "; 
        } else {
            std::cout << "00 ";
        }
    }
    std::cout << std::endl;
}
}