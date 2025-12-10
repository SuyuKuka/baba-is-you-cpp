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
    vector<int> stopId;
    vector<int> winId;
    vector<int> openId;
    vector<int> shutId;
    ruleProcessor->initIds(stopId, winId, openId, shutId);

    vector<Entity*> entities = ruleProcessor->isYou();
    if (entities.size() > 0) {
        for (Entity* entity: entities) {
            Position pos = entity->getPosition();
            Position newPos = pos + dPos;
            if (newPos.x >= 0 && newPos.x < map->getWidth() && newPos.y >= 0 && newPos.y < map->getHeight()) {
                if (!ruleProcessor->isStop(newPos, stopId)) {
                    if (ruleProcessor->isOpen(newPos, dPos, openId, shutId)) applyOpen(newPos, dPos, openId, shutId);
                    if (ruleProcessor->isNextPushable(newPos)) applyPush(pos, newPos, dPos, stopId, move);
                    if (move) {
                        if (isPulling) {
                            Position pullPos = pos - dPos; 
                            ruleProcessor->updatePullable(pullPos);          
                            applyPull(pullPos, pos);
                        }
                        EntityState current = EntityState(entity, pos, entity -> getId());
                        undoRedoHandler.addUndoState(current);
                        map->removeCell(pos, entity); 
                        entity->setPosition(newPos);
                        map->addCell(newPos, entity);
                        oneWasMoved = true;
                    }
                    if (ruleProcessor->isWin(newPos, winId)) {
                        win = true;
                        undoRedoHandler.clear();
                        return;
                    }
                } 
            }
        }
        if (oneWasMoved) undoRedoHandler.addDirection(lastDirection);
    }
}

void MainModel::applyPush(const Position& pos, Position& newPos, const Position& dPos, const vector<int> stopId, bool& move) {
    while (true) {
        // Zone inaccessible donc on empeche d'avancer et on reprend la position precedente
        if (newPos.x < 0 || newPos.x >= map->getWidth() || newPos.y < 0 || newPos.y >= map->getHeight() || ruleProcessor->isStop(newPos, stopId)) {
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
        if (!move || newPos == pos) { return; } // On sort si on ne peut pas avancer
        Cell& cell = (*map)[newPos - dPos];
        for (size_t i = 0; i < cell.getEntities().size(); i++) {
            Entity* pushed = (*map)[newPos - dPos].getEntities()[i];
            if (pushed->isPushable()) {
                EntityState current = EntityState(pushed, newPos - dPos, pushed -> getId());
                undoRedoHandler.addUndoState(current);
                map->removeCell(newPos - dPos, pushed);
                pushed->setPosition(newPos);
                map->addCell(newPos, pushed);
                newPos -= dPos;
            }
        }
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

void MainModel::applyOpen(Position newPos, const Position& dPos, vector<int>& openId, vector<int>& shutId) {
    EntityState current;
    Cell& cell = (*map)[newPos];
    for (Entity* entity : cell.getEntities()) {
        if (find(openId.begin(), openId.end(), entity->getId()) != openId.end()) {
            current = EntityState(entity, newPos, entity -> getId());
            undoRedoHandler.addUndoState(current);
            entity -> setId(static_cast<int>(GameEntity::NONE));
            map->removeCell(newPos, entity);
            break;
        }
    }

    Cell& cell2 = (*map)[newPos + dPos];
    for (Entity* entity : cell2.getEntities()) {
        if (find(shutId.begin(), shutId.end(), entity->getId()) != shutId.end()) {
            current = EntityState(entity, newPos + dPos, entity -> getId());
            undoRedoHandler.addUndoState(current);
            entity -> setId(static_cast<int>(GameEntity::NONE));
            map->removeCell(newPos + dPos, entity);
            break;
        }
    }
}

void MainModel::applyPull(const Position& pullPos, const Position& newPos) {
    Cell& cell = (*map)[pullPos];
    vector<Entity *> entities = cell.getEntities();
    for (size_t i = 0; i < entities.size(); i++) {
        Entity* pulled = entities[i];
        if (pulled->isPullable()) {
            EntityState current = EntityState(pulled, pullPos, pulled -> getId());
            undoRedoHandler.addUndoState(current);
            map->removeCell(pullPos, pulled);
            pulled->setPosition(newPos);
            map->addCell(newPos, pulled);
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
}