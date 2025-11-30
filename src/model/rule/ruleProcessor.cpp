#include "model/rule/ruleProcessor.hpp"
#include "model/map/map.hpp"

void RuleProcessor::initIds(vector<int>& youId, vector<int>& stopId, vector<int>& winId) const {
    for (const Rule& rule : map.getRuleEngine().getActiveRules()) {
        if (rule.properties == PropertyWordEntity::TEXTYOU) {
            int gameEntity = static_cast<int>(rule.subjects) - 20;
            youId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTSTOP) {
            int gameEntity = static_cast<int>(rule.subjects) - 20;
            stopId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTWIN) {
            int gameEntity = static_cast<int>(rule.subjects) - 20;
            winId.push_back(gameEntity);
        }
    }
}

const vector<Entity*> RuleProcessor::isYou(const vector<int> youId) {
    vector<Entity*> entities;
    for (Entity* entity : map.getNounsEntityOnMap()) {
        if (find(youId.begin(), youId.end(), entity->getId()) != youId.end()) {
            entities.push_back(entity);
        }
    }
    return entities;
}

bool RuleProcessor::isStop(const Position& newPos, const vector<int>& stopId) const {
    for (Entity* entity : map.getNounsEntityOnMap()) {
        if (find(stopId.begin(), stopId.end(), entity->getId()) != stopId.end()) {
            Position pos = entity->getPosition();
            if (newPos == pos) {
                return true;
            }
        }
    }
    return false;
}

bool RuleProcessor::isNextPushable(const Position& newPos) const {
    vector<int> entityPushableRules;
    for (const Rule& rule : map.getRuleEngine().getActiveRules()) { 
        if (rule.properties == PropertyWordEntity::TEXTPUSH) {
            int gameEntity = static_cast<int>(rule.subjects) - 20;
            entityPushableRules.push_back(gameEntity);
        }
    }

    const Cell& cell = map[newPos];
    for (size_t i = 0; i < cell.getEntities().size(); i++) {
        Entity* pushed = cell.getEntities()[i];
        if (pushed->isPushable()) {
            return true;
        }
        if (find(entityPushableRules.begin(), entityPushableRules.end(), pushed->getId()) != entityPushableRules.end()) {
            pushed->setIsPushable(true);
            return true;
        } 
    }
    return false;
}

bool RuleProcessor::isWin(const Position& newPos, const vector<int>& winId) const {
    for (Entity* entity : map.getNounsEntityOnMap()) {
        if (find(winId.begin(), winId.end(), entity->getId()) != winId.end()) {
            Position pos = entity->getPosition();
            if (newPos == pos) {
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