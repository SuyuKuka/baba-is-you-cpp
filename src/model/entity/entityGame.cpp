#include "model/entity/entityGame.hpp"

bool EntityGame::isPushable() const {
    return false;
}

bool EntityGame::isStackable() const {
    return false;
}

bool EntityGame::isDestroyable() const {
    return false;
}

GameEntity EntityGame::getGameEntity() const {
    return static_cast<GameEntity>(getId());
}