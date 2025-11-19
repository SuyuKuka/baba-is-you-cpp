#include "model/map.hpp"

Map::Map(int width, int height) : width(width), height(height) {
    map.resize(height, vector<Cell>(width));
}

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].entities.push_back(entity);
}
