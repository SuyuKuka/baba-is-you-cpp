#include "model/map/map.hpp"

Map::Map(int width, int height): width(width), height(height) {
    rules = new RuleEngine(*this);
    ruleProcessor = new RuleProcessor(*this);
    map.resize(height, vector<Cell>(width));
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

Cell& Map::operator[](const Position& pos) {
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height) {
        throw out_of_range("Position out of bounds in Map operator[] (non-const)");
    }
    return map[pos.y][pos.x]; 
}

const Cell& Map::operator[](const Position& pos) const {
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height) {
        throw out_of_range("Position out of bounds in Map operator[]");
    }
    return map[pos.y][pos.x];
}

void Map::addCell(Position pos, Entity* entity) {
    (*this)[pos].addEntity(entity);
}

void Map::removeCell(Position pos, Entity* entity) {
    (*this)[pos].removeEntity(entity);
}

void Map::addNounTextOnMap(Entity* noun) {
    nounsTextOnMap.push_back(noun);
}

void Map::addNounEntityOnMap(Entity* noun) {
    nounsEntityOnMap.push_back(noun);
}

void Map::update(const Position dPos, const bool& pull) {
    move(dPos, pull);
    rules->updateRules();

    vector<Rule> transformationRules = ruleProcessor->isTransformation();
    if (transformationRules.size() > 0) {
        for (Rule& rule : transformationRules) {
            applyTransformations(rule);
        }
    }
}

void Map::move(const Position& dPos, const bool& pull) {
    bool move = true;
    vector<int> stopId;
    vector<int> winId;
    ruleProcessor->initIds(stopId, winId);
    ruleProcessor->initIds(stopId, winId);

    vector<Entity*> entities = ruleProcessor->isYou();
    if (entities.size() > 0) {
        for (Entity* entity: entities) {
            Position pos = entity->getPosition();
            Position newPos = pos + dPos;
            if (newPos.x >= 0 && newPos.x < width && newPos.y >= 0 && newPos.y < height) {
                if (!ruleProcessor->isStop(newPos, stopId)) {
                    if (ruleProcessor->isNextPushable(newPos)) {
                        applyPush(pos, newPos, dPos, stopId, move);
                    }
                    if (move) {
                        if (pull) {
                            Position pullPos = pos - dPos; 
                            ruleProcessor->updatePullable(pullPos);                            
                            applyPull(pullPos, pos);
                        }
                        removeCell(pos, entity); 
                        entity->setPosition(newPos);
                        addCell(newPos, entity);
                    }
                    if (ruleProcessor->isWin(newPos, winId)) {
                        cout << "You win !" << endl;
                    }
                } 
            }
        }
    }
}

void Map::applyPull(const Position& pullPos, const Position& newPos) {
    Cell& cell = (*this)[pullPos];
    vector<Entity *> entities = cell.getEntities();
    for (size_t i = 0; i < entities.size(); i++) {
        Entity* pulled = entities[i];
        if (pulled->isPullable()) {
            removeCell(pullPos, pulled);
            pulled->setPosition(newPos);
            addCell(newPos, pulled);
        }
    }
}

void Map::applyPush(const Position& pos, Position& newPos, const Position& dPos, const vector<int> stopId, bool& move) {
    while (true) {
        // Zone inaccessible donc on empeche d'avancer et on reprend la position precedente
        if (newPos.x < 0 || newPos.x >= width || newPos.y < 0 || newPos.y >= height || ruleProcessor->isStop(newPos, stopId)) {
            move = false;
            newPos -= dPos;
            break;
        }
        if (!ruleProcessor->isNextPushable(newPos)) {
            break;
        }
        newPos += dPos;
    }

    // On deplace les objets qu'on peut pousser en commencant par la dernière position
    while (newPos.x != pos.x + dPos.x || newPos.y != pos.y + dPos.y) {
        Cell& cell = (*this)[newPos - dPos];
        for (size_t i = 0; i < cell.getEntities().size(); i++) {
            Entity* pushed = (*this)[newPos - dPos].getEntities()[i];
            if (pushed->isPushable()) {
                removeCell(newPos - dPos, pushed);
                pushed->setPosition(newPos);
                addCell(newPos, pushed);
                newPos -= dPos;
            }
        }
    }
}

void Map::applyTransformations(const Rule& rule) {
    int subject = static_cast<int>(rule.subjects) - 4;
    int transformation = static_cast<int>(rule.transformation) - 4;
    for (Entity* entity : nounsEntityOnMap) {
        if (entity->getId() == subject) {
            entity->setId(transformation);
        }
    }
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
    return occupiedCells;
}