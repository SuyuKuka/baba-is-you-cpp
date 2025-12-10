#include "model/mainModel.hpp"

MainModel::MainModel(): map(nullptr), rules(nullptr), ruleProcessor(nullptr), win(false) {

}

void MainModel::init(Map* map) {
    win = false;
    this->map = map;
    rules = new RuleEngine(*this);
    ruleProcessor = new RuleProcessor(*this);
    rules->updateRules();
}

MainModel::~MainModel() {
    delete rules;
    delete ruleProcessor;
}

void MainModel::update(const Position& dPos, const bool& isPulling, const Direction& lastDirection) {
    undoRedoHandler.emptyRedo();
    undoRedoHandler.emptyRedoDirection();
    undoRedoHandler.next();
    move(dPos, isPulling, lastDirection);
    getRuleEngine().updateRules();

    vector<Rule> transformationRules = ruleProcessor->isTransformation();
    if (transformationRules.size() > 0) {
        for (Rule& rule : transformationRules) {
            applyTransformations(rule);
        }
    }
    undoRedoHandler.removeTopEmpty();
}

void MainModel::move(const Position& dPos, const bool& isPulling, const Direction& lastDirection) {
    bool move = true;
    bool oneWasMoved = false;
    
    ruleProcessor->initIds();

    vector<Entity*> entities = ruleProcessor->isYou();
    if (entities.size() > 0) {
        checkMove(entities, dPos, isPulling, lastDirection, move, oneWasMoved);
    }
}

void MainModel::checkMove(vector<Entity*>& entities, const Position& dPos, const bool& isPulling, const Direction& lastDirection, bool& move, bool& oneWasMoved) {
    for (Entity* entity: entities) {
        Position pos = entity->getPosition();
        Position newPos = pos + dPos;
        if (newPos.x >= 0 && newPos.x < map->getWidth() && newPos.y >= 0 && newPos.y < map->getHeight()) {
            if (!ruleProcessor->isStop(newPos)) {
                if (ruleProcessor->isOpen(newPos, dPos)) applyOpen(newPos, dPos);
                if (ruleProcessor->isNextPushable(newPos)) applyPush(pos, newPos, dPos, move);
                if (move) {
                    if (isPulling) applyPull(pos, dPos);
                    applyMove(entity, pos, newPos, oneWasMoved);
                }
                if (ruleProcessor->isWin(newPos)) {
                    win = true;
                    undoRedoHandler.clear();
                    return;
                }
            } 
        }
        move = true;
    }
    if (oneWasMoved) undoRedoHandler.addDirection(lastDirection);
}

void MainModel::applyMove(Entity* entity, const Position& pos, const Position& newPos, bool& oneWasMoved) {
    EntityState current = EntityState(entity, pos, entity -> getId());
    undoRedoHandler.addUndoState(current);
    map->removeCell(pos, entity); 
    entity->setPosition(newPos);
    map->addCell(newPos, entity);
    oneWasMoved = true;
}

void MainModel::applyPush(const Position& pos, Position& newPos, const Position& dPos, bool& move) {
    bool tmp = true;
    findLastPushable(newPos, dPos, move);
    // On deplace les objets qu'on peut pousser en commencant par la dernière position
    while (newPos.x != pos.x + dPos.x || newPos.y != pos.y + dPos.y) {
        if (!move || newPos == pos) { return; } // On sort si on ne peut pas avancer
        Cell& cell = (*map)[newPos - dPos];
        for (size_t i = 0; i < cell.getEntities().size(); i++) {
            Entity* pushed = (*map)[newPos - dPos].getEntities()[i];
            if (find(ruleProcessor->getYouID().begin(), ruleProcessor->getYouID().end(), pushed->getId()) != ruleProcessor->getYouID().end()) {
                newPos -= dPos;
                continue;
            }
            if (pushed->isPushable()) {
                applyMove(pushed, newPos - dPos, newPos, tmp);
                newPos -= dPos;
            }
        }
    }
}

void MainModel::findLastPushable(Position& newPos, const Position& dPos, bool& move) {
    const vector<int> stopId = ruleProcessor->getStopID();
    while (true) {
        // Zone inaccessible donc on empeche d'avancer et on reprend la position precedente
        if (newPos.x < 0 || newPos.x >= map->getWidth() || newPos.y < 0 || newPos.y >= map->getHeight() || ruleProcessor->isStop(newPos)) {
            move = false;
            newPos -= dPos;
            break;
        }
        if (!ruleProcessor->isNextPushable(newPos)) {
            break;
        }
        newPos += dPos;
    }
}

void MainModel::applyTransformations(const Rule& rule) {
    int subject = static_cast<int>(rule.subjects) - 100;
    int transformation = static_cast<int>(rule.transformation) - 100;
    for (Entity* entity : map->getNounsEntityOnMap()) {
        if (entity->getId() == subject) {
            EntityState current = EntityState(entity, entity -> getPosition(), entity -> getId());
            undoRedoHandler.addUndoState(current);
            entity->setId(transformation);
        }
    }
}

void MainModel::applyOpen(Position newPos, const Position& dPos) {
    vector<int> openId = ruleProcessor->getOpenID();
    vector<int> shutId = ruleProcessor->getShutID();

    removeEntity(newPos, openId);
    removeEntity(newPos + dPos, shutId);
}

void MainModel::removeEntity(const Position& pos, const std::vector<int>& targetIds) {
    Cell& cell = (*map)[pos];
    for (Entity* entity : cell.getEntities()) {
        if (std::find(targetIds.begin(), targetIds.end(), entity->getId()) != targetIds.end()) {
            EntityState current(entity, pos, entity->getId());
            undoRedoHandler.addUndoState(current);
            entity->setId(static_cast<int>(GameEntity::NONE));
            map->removeCell(pos, entity);
            break; 
        }
    }
}

void MainModel::applyPull(const Position& newPos, const Position& dPos) {
    Position pullPos = newPos - dPos; 
    ruleProcessor->updatePullable(pullPos);   
    
    bool tmp = true;
    Cell& cell = (*map)[pullPos];
    vector<Entity *> entities = cell.getEntities();
    for (size_t i = 0; i < entities.size(); i++) {
        Entity* pulled = entities[i];
        if (pulled->isPullable()) {
            applyMove(pulled, pullPos, newPos, tmp);
        }
    }
}

Direction MainModel::undo() {
    vector<EntityState> undoStep = undoRedoHandler.undoStep();
    for (EntityState state : undoStep) {
        map -> removeCell(state.getPosAfter(), state.getEntity());
        map -> addCell(state.getPosBefore(), state.getEntity());
    }
    Direction undoDirection = undoRedoHandler.getDirection();
    return undoDirection;
}

Direction MainModel::redo() {
    vector<EntityState> redoStep =undoRedoHandler.redoStep();
    for (EntityState state : redoStep) {
        map -> removeCell(state.getPosBefore(), state.getEntity());
        map -> addCell(state.getPosAfter(), state.getEntity());
    }
    Direction redoDirection = undoRedoHandler.getDirection();
    return redoDirection;
}

bool MainModel::inBounds(const Position& pos) const {
    return pos.x >= 0 && pos.x < map->getWidth() && pos.y >= 0 && pos.y < map->getHeight();

Map* MainModel::getMap() const { 
    return map; 
}

RuleEngine& MainModel::getRuleEngine() const { 
    return *rules; 
}

RuleProcessor& MainModel::getRuleProcessor() const { 
    return *ruleProcessor; 
}

bool MainModel::isWin() const { 
    return win; 

}