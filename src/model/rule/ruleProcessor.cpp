#include "model/rule/ruleProcessor.hpp"
#include "model/mainModel.hpp"

void RuleProcessor::initIds(vector<int>& stopId, vector<int>& winId, vector<int>& openId, vector<int>& shutId) const {
    youId.clear();
    for (const Rule& rule: game.getRuleEngine().getActiveRules()) {
        int gameEntity = static_cast<int>(rule.subjects) - 100;
        if (rule.properties == PropertyWordEntity::TEXTYOU) {
            youId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTSTOP) {
            stopId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTWIN) {
            winId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTOPEN) {
            openId.push_back(gameEntity);
        } else if (rule.properties == PropertyWordEntity::TEXTSHUT) {
            shutId.push_back(gameEntity);
        }
    }
}

const vector<Entity*> RuleProcessor::isYou() const {
    vector<Entity*> entities;
    for (Entity* entity : game.getMap()->getNounsEntityOnMap()) {
        if (find(youId.begin(), youId.end(), entity->getId()) != youId.end()) {
            entities.push_back(entity);
        }
    }
    return entities;
}

bool RuleProcessor::isStop(const Position& newPos, const vector<int>& stopId) const {
    for (Entity* entity : game.getMap()->getNounsEntityOnMap()) {
        if (find(stopId.begin(), stopId.end(), entity->getId()) != stopId.end()) {
            Position pos = entity->getPosition();
            if (newPos == pos) {
                return true;
            }
        }
    }
    return false;
}

void RuleProcessor::updatePullable(const Position& pullPos) const {
    vector<int> entityPullableRules;
    for (const Rule& rule : game.getRuleEngine().getActiveRules()) {
        if (rule.properties == PropertyWordEntity::TEXTPULL) {
            int gameEntity = static_cast<int>(rule.subjects) - 100;
            entityPullableRules.push_back(gameEntity);
        }
    }

    const Cell& cell = (*game.getMap())[pullPos];
    const vector<Entity *> entities = cell.getEntities();
    for (size_t i = 0; i < entities.size(); i++) {
        Entity* entity = entities[i];
        if (entity -> isPullable()) {
            break;
        }
        if (find(entityPullableRules.begin(), entityPullableRules.end(), entity->getId()) != entityPullableRules.end()) {
            entity->setPullable(true);
        }
    }
}

bool RuleProcessor::isNextPushable(const Position& newPos) const {
    vector<int> entityPushableRules;
    for (const Rule& rule : game.getRuleEngine().getActiveRules()) { 
        if (rule.properties == PropertyWordEntity::TEXTPUSH) {
            int gameEntity = static_cast<int>(rule.subjects) - 100;
            entityPushableRules.push_back(gameEntity);
        }
    }

    const Cell& cell = (*game.getMap())[newPos];
    for (size_t i = 0; i < cell.getEntities().size(); i++) {
        Entity* pushed = cell.getEntities()[i];
        if (pushed->isPushable()) {
            return true;
        }
        if (find(entityPushableRules.begin(), entityPushableRules.end(), pushed->getId()) != entityPushableRules.end()) {
            pushed->setPushable(true);
            return true;
        } 
    }
    return false;
}

bool RuleProcessor::isWin(const Position& newPos, const vector<int>& winId) const {
    for (Entity* entity : game.getMap()->getNounsEntityOnMap()) {
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
    const vector<Rule>& activeRules = game.getRuleEngine().getActiveRules();
    vector<Rule> transformationRules;
    for (const Rule& rule : activeRules) {
        if (rule.transformation != NounWordEntity::NONE) {
            transformationRules.push_back(rule);
        }
    }
    return transformationRules;
}

bool RuleProcessor::isOpen(const Position newPos, const Position& dPos, const vector<int>& openId, const vector<int>& shutId) const {
    for (const Entity* entity : (*game.getMap())[newPos].getEntities()) {
        if (find(openId.begin(), openId.end(), entity->getId()) != openId.end()) {
            for (const Entity* entity2 : (*game.getMap())[newPos + dPos].getEntities()) {
                if (find(shutId.begin(), shutId.end(), entity2->getId()) != shutId.end()) {
                    return true;
                }
            }
        }
    }
    return false;
}

const vector<int>& RuleProcessor::getYouID() const { 
    return youId; 
}

bool RuleProcessor::babaIsYou() const {
    return find(youId.begin(), youId.end(), static_cast<int> (GameEntity::BABA)) != youId.end();
}