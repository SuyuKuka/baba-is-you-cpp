#include "model/rule/ruleProcessor.hpp"
#include "model/map/map.hpp"

void RuleProcessor::initIds(vector<int>& youId, vector<int>& stopId, vector<int>& winId) const {
    for (const Rule& rule : map.getRuleEngine().getActiveRules()) {
        if (rule.properties == PropertyWordEntity::TEXTYOU) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            youId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTSTOP) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            stopId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTWIN) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            winId.push_back(gameEntity);
        }
    }
}

const vector<Entity*> RuleProcessor::isYou(const vector<int> youId) {
    vector<Entity*> entities;
    for (Entity* entity : map.getNounsEntityOnMap()) {
        if (std::find(youId.begin(), youId.end(), entity->getId()) != youId.end()) {
            entities.push_back(entity);
        }
    }
    return entities;
}

bool RuleProcessor::isStop(const int newX, const int newY, const vector<int> stopId) const {
    for (Entity* entity : map.getNounsEntityOnMap()) {
        if (std::find(stopId.begin(), stopId.end(), entity->getId()) != stopId.end()) {
            int x = entity->getX();
            int y = entity->getY();
            if (newX == x && newY == y) {
                return true;
            }
        }
    }
    return false;
}

bool RuleProcessor::isNextPushable(const int newX, const int newY) const {
    vector<int> entityPushableRules;
    for (const Rule& rule : map.getRuleEngine().getActiveRules()) { 
        if (rule.properties == PropertyWordEntity::TEXTPUSH) {
            int gameEntity = static_cast<int>(rule.subjects) - 4;
            entityPushableRules.push_back(gameEntity);
        }
    }

    const Cell& cell = map.getCell(newX, newY);
    for (size_t i = 0; i < cell.getEntities().size(); i++) {
        Entity* pushed = cell.getEntities()[i];
        if (pushed->isPushable() || 
            std::find(entityPushableRules.begin(), entityPushableRules.end(), pushed->getId()) != entityPushableRules.end()
        ) {
            return true;
        } 
    }
    return false;
}

bool RuleProcessor::isWin(const int newX, const int newY, const vector<int> winId) const {
    for (Entity* entity : map.getNounsEntityOnMap()) {
        if (std::find(winId.begin(), winId.end(), entity->getId()) != winId.end()) {
            int x = entity->getX();
            int y = entity->getY();
            if (newX == x && newY == y) {
                return true;
            }
        }
    }
    return false;
}

const vector<Rule> RuleProcessor::isTransformation() {
    const vector<Rule>& activeRules = map.getRuleEngine().getActiveRules();
    vector<Rule> transformationRules;
    for (const Rule& rule : activeRules) {
        if (rule.transformation != NounWordEntity::NONE) {
            transformationRules.push_back(rule);
        }
    }
    return transformationRules;
}