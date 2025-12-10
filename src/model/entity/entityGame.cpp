#include "model/entity/entityGame.hpp"

EntityGame::EntityGame(Position pos, int id): Entity(pos, id) {
    pushable = false;
    pullable = false;
}

bool EntityGame::isPushable() const {
    return pushable;
}

bool EntityGame::isPullable() const {
    return pullable;
}

void EntityGame::setPushable(bool pushable) {
    this->pushable = pushable;
}

void EntityGame::setPullable(const bool pullable) {
    this->pullable = pullable;
}

GameEntity EntityGame::getGameEntity() const {
    return static_cast<GameEntity>(getId());
}