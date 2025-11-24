#include "model/map.hpp"

void Map::updateRules() {
    rules.clearActiveRules();
    for (Entity* nounEntity : nouns) {
        int x = nounEntity->getX();
        int y = nounEntity->getY();
        
        checkRule(x, y, nounEntity, true);
        checkRule(x, y, nounEntity, false);
    }
}

void Map::checkRule(int x, int y, Entity* nounEntity, bool isHorizontal) {
    int dx = isHorizontal ? 1 : 0;
    int dy = isHorizontal ? 0 : 1;
    if ((x + 2 * dx >= width) || (y + 2 * dy >= height)) {
        return;
    }
    
    // Check si y'a un opérateur
    int xOp = x + dx;
    int yOp = y + dy;
    const std::vector<Entity*>& entitiesOp = map[yOp][xOp].getEntities();
    if (entitiesOp.empty() || !entitiesOp[0]->isOperatorText()) {
        return;
    }
    
    // Check si y'a une propriété ou un nom
    int xTarget = x + 2 * dx;
    int yTarget = y + 2 * dy;
    const std::vector<Entity*>& entitiesTarget = map[yTarget][xTarget].getEntities();
    if (entitiesTarget.empty()) {
        return;
    }

    Entity* targetEntity = entitiesTarget[0];
    if (targetEntity->isPropertyText()) {
        rules.addActiveRule(
            nounEntity->getNounType(),
            targetEntity->getPropertyType(),
            NounType::NONE
        );
    } else if (targetEntity->isNounText()) {
        rules.addActiveRule(
            nounEntity->getNounType(),
            PropertyType::NONE,
            targetEntity->getNounType()
        );
    }
}

void Map::addCell(int x, int y, Entity* entity) {
    map[y][x].addEntity(entity);
}

void Map::addNoun(Entity* noun) {
    if (noun != nullptr) {
        nouns.push_back(noun);
    }
}

const Cell& Map::getCell(int x, int y) const {
    return map[y][x];
}

const Rule& Map::getRules() const {
    return rules;
}

void Map::clearNouns() {
    nouns.clear();
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

void Map::printRules() const {
    cout << "Nouns: ";

    for (Entity* noun : nouns) {

        cout << noun->getId() << " ";

    }
    cout << endl;
    rules.printActivesRules();
}