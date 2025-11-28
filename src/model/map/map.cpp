#include "model/map/map.hpp"

Map::Map(int width, int height): width(width), height(height), rules(*this) {
    map.resize(height, std::vector<Cell>(width));
}

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].addEntity(entity);
}

void Map::removeCell(int x, int y, Entity* entity) {
    map[y][x].removeEntity(entity);
}

void Map::addNounTextOnMap(Entity* noun) {
    nounsTextOnMap.push_back(noun);
}

void Map::addNounEntityOnMap(Entity* noun) {
    nounsEntityOnMap.push_back(noun);
}

const Cell& Map::getCell(int x, int y) const {
    return map[y][x];
}

void Map::initIds(vector<int>& youId, vector<int>& stopId, vector<int>& winId) {
    for (const Rule& rule : rules.getActiveRules()) {
        if (rule.properties == PropertyWordEntity::TEXTYOU) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            youId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTSTOP) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            stopId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTWIN) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            winId.push_back(gameEntity);
        }
    }
}

void Map::move(const int dx, const int dy) {
    vector<int> youId;
    vector<int> stopId;
    vector<int> winId;

    initIds(youId, stopId, winId);

    for (Entity* entity : nounsEntityOnMap) {
        if (std::find(youId.begin(), youId.end(), entity->getId()) != youId.end()) {
            int x = entity->getX();
            int y = entity->getY();
            int newX = x + dx;
            int newY = y + dy;
            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                if (!isStop(newX, newY, stopId)) {
                    if (isPushable(newX, newY)) {
                        executePush(x, y, newX, newY, dx, dy);
                    }
                    removeCell(x, y, entity); 
                    entity->setX(newX);
                    entity->setY(newY);
                    addCell(newX, newY, entity);
                }
            }
        }
    }
}

void Map::executePush(const int x, const int y, int& newX, int& newY, const int dx, const int dy) {
    while (isPushable(newX, newY)) {
        if (newX < 0 || newX >= width || newY < 0 || newY >= height) {
            break;
        }
        newX += dx;
        newY += dy;
    }
    
    while (newX != x + dx || newY != y + dy) {
        const Cell& cell = getCell(newX - dx, newY - dy);
        for (size_t i = 0; i < cell.getEntities().size(); i++) {
            Entity* pushed = map[newY - dy][newX - dx].getEntities()[i];
            if (pushed->isPushable()) {
                removeCell(newX - dx, newY - dy, pushed);
                pushed->setX(newX);
                pushed->setY(newY);
                addCell(newX, newY, pushed);
                newX -= dx;
                newY -= dy;
            }
        }
    }
}

bool Map::isStop(const int newX, const int newY, const vector<int> stopId) const {
    for (Entity* entity : nounsEntityOnMap) {
        if (std::find(stopId.begin(), stopId.end(), entity->getId()) != stopId.end()) {
            int x = entity->getX();
            int y = entity->getY();
            if (newX == x && newY == y) {
                return true;
            }
        }
    }
    return false;
}

bool Map::isPushable(const int newX, const int newY) const {
    const Cell& cell = map[newY][newX];
    for (size_t i = 0; i < cell.getEntities().size(); i++) {
        Entity* pushed = cell.getEntities()[i];
        if (pushed->isPushable()) {
            return true;
        }
    }
    return false;
}

void Map::clear() {
    for (vector<Cell>& list : map) {
        for (Cell& cell : list) {
            cell.deleteEntities();
        }
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
