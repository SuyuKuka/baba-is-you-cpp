#ifndef ENTITY_NOUN_HPP
#define ENTITY_NOUN_HPP
#include "model/entity/entity.hpp"
#include "model/map/map.hpp"

class EntityGame: public Entity {
private:
    vector<vector<Cell>> map;
    vector<Rule> activesRules;
public:
    EntityGame(int x, int y, int id, Map& map): Entity(x, y, id) {
        this->map = map.getMap();
        this->activesRules = map.getRuleEngine().getActiveRules();
    }

    void update();
    bool isPushable() const override;
    bool isStackable() const override;
    bool isDestroyable() const override;
    GameEntity getGameEntity() const override;
};

#endif