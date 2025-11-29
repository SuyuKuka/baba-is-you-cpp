#include "model/map/map.hpp"

Map::Map(int width, int height): width(width), height(height) {
    rules = new RuleEngine(*this);
    ruleProcessor = new RuleProcessor(*this);
    map.resize(height, std::vector<Cell>(width));
}

Map::~Map() {
    for (vector<Cell>& list : map) {
        for (Cell& cell : list) {
            cell.deleteEntities();
        }
    }
    delete ruleProcessor;
    delete rules;
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

void Map::update(const int dx, const int dy) {
    move(dx, dy);
    rules->updateRules();

    vector<Rule> transformationRules = ruleProcessor->isTransformation();
    if (transformationRules.size() > 0) {
        for (Rule rule : transformationRules) {
            applyTransformations(rule);
        }
    }
}

void Map::move(const int dx, const int dy) {
    vector<int> youId;
    vector<int> stopId;
    vector<int> winId;
    ruleProcessor->initIds(youId, stopId, winId);

    vector<Entity*> entities = ruleProcessor->isYou(youId);
    if (entities.size() > 0) {
        for (Entity* entity: entities) {
            int x = entity->getX();
            int y = entity->getY();
            int newX = x + dx;
            int newY = y + dy;
            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                if (!ruleProcessor->isStop(newX, newY, stopId)) {
                    if (ruleProcessor->isNextPushable(newX, newY)) {
                        executePush(x, y, newX, newY, dx, dy);
                    }
                    removeCell(x, y, entity); 
                    entity->setX(newX);
                    entity->setY(newY);
                    addCell(newX, newY, entity);
                    if (ruleProcessor->isWin(newX, newY, winId)) {
                        cout << "You win !" << endl;
                    }
                } 
            }
        }
    }
}

void Map::executePush(const int x, const int y, int& newX, int& newY, const int dx, const int dy) {
    while (ruleProcessor->isNextPushable(newX, newY)) {
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

void Map::applyTransformations(Rule rule) {
    int subject = static_cast<int>(rule.subjects) - 4;
    int transformation = static_cast<int>(rule.transformation) - 4;
    for (Entity* entity : nounsEntityOnMap) {
        if (entity->getId() == subject) {
            entity->setId(transformation);
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
