#include "model/map/cell.hpp"

const vector<Entity*>& Cell::getEntities() const {
    return entities;
}

void Cell::deleteEntities() {
    for (Entity* entity : entities) {
        delete entity;
    }
    entities.clear();
}

void Cell::addEntity(Entity* entity) {
    entities.push_back(entity);
}

void Cell::removeEntity(Entity* entity) {
    entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
}

bool Cell::isEmpty() const {
    return entities.empty();
}

size_t Cell::hasNounEntity() const {
    for (size_t i = 0; i < entities.size(); i++) {
        if (entities[i]->isNounWordEntity()) {
            return i;
        }
    }
    return -1;
}

size_t Cell::hasOperatorEntity() const {
    for (size_t i = 0; i < entities.size(); i++) {
        if (entities[i]->isOperatorWordEntity()) {
            return i;
        }
    }
    return -1;
}

size_t Cell::hasPropertyEntity() const {
    for (size_t i = 0; i < entities.size(); i++) {
        if (entities[i]->isPropertyWordEntity()) {
            return i;
        }
    }
    return -1;
}

bool Cell::isIS() const {
    for (size_t i = 0; i < entities.size(); i++) {
        if (entities[i]->getId() == static_cast<int>(OperatorWordEntity::TEXTIS)) {
            return true;
        }
    }
    return false;
}