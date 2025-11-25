#include "model/map.hpp"

Map::Map(int width, int height): width(width), height(height), rules(*this) {
    map.resize(height, std::vector<Cell>(width));
}

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].addEntity(entity);
}

void Map::removeCell(int x, int y, Entity* entity) {
    map[y][x].removeEntity(entity);
}

void Map::addNoun(Entity* noun) {
    nouns.push_back(noun);
}

void Map::addNounEntityType(Entity* noun) {
    nounsEntityType.push_back(noun);
}

const Cell& Map::getCell(int x, int y) const {
    return map[y][x];
}

void Map::clearNouns() {
    nouns.clear();
}

void Map::printMap() {
    std::cout << "************************Map************************" << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Cell& cell = map[y][x]; 
            
            if (!cell.isEmpty()) {
                Entity* entity = cell.getEntities()[0]; 
                int id = entity->getId();
                std::cout << id << " "; 
            } else {
                std::cout << "00 ";
            }
        }
        std::cout << std::endl;
    }
}

void Map::printRules() const {
    cout << "Nouns: ";
    for (Entity* noun : nouns) {
        cout << noun->getId() << " ";
    }
    cout << endl;
    rules.printActivesRules();
}

void Map::move(int dx, int dy) {
    for (const auto& rule : rules.getActiveRules()) {
        if (rule.properties == PropertyWordEntity::TEXTYOU) {
            int GameEntity = static_cast<int>(rule.subjects) - 9;
            for (Entity* entity : nounsEntityType) {
                if (entity->getId() == GameEntity) {
                    int x = entity->getX();
                    int y = entity->getY();
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                        if (checkMove(newX, newY)) {
                            removeCell(x, y, entity); 
                            entity->setX(newX);
                            entity->setY(newY);
                            addCell(newX, newY, entity);

                            printMap();
                            return;
                        } else {
                            std::cout << "STOP" << std::endl;
                        }
                    } else {
                        std::cout << "Error: Invalid move" << std::endl;
                    }
                }
            }
        }
    }
}

bool Map::checkMove(int newX, int newY) {
    for (const auto& rule : rules.getActiveRules()) {
        if (rule.properties == PropertyWordEntity::TEXTSTOP) {
            int GameEntity = static_cast<int>(rule.subjects) - 9;
            for (Entity* entity : nounsEntityType) {
                if (entity->getId() == GameEntity) {
                    int x = entity->getX();
                    int y = entity->getY();
                    if (newX == x && newY == y) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}