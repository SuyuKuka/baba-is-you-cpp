#include "model/map.hpp"

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].entities.push_back(entity);
}

void Map::printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << map[i][j].entities.size() << " ";
        }
        std::cout << std::endl;
    }
}