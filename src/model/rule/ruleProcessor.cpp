#include "model/rule/ruleProcessor.hpp"
#include "model/map/map.hpp"

void RuleProcessor::initIds(vector<int>& youId, vector<int>& stopId, vector<int>& winId) {
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
    const Cell& cell = map.getCell(newX, newY);
    for (size_t i = 0; i < cell.getEntities().size(); i++) {
        Entity* pushed = cell.getEntities()[i];
        if (pushed->isPushable()) {
            return true;
        }
    }
    return false;
}