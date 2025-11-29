#include "model/rule/ruleEngine.hpp"
#include "model/map/map.hpp"

void RuleEngine::addActiveRule(NounWordEntity noun, OperatorWordEntity ope, PropertyWordEntity property, NounWordEntity transform) {
    Rule rule;
    rule.subjects = noun;
    rule.operators = ope;
    rule.properties = property;
    rule.transformation = transform;
    activeRules.push_back(rule);
}

const vector<Rule> RuleEngine::getActiveRules() const {
    return activeRules;
}

void RuleEngine::clearActiveRules() {
    activeRules.clear();
}

void RuleEngine::printActivesRules() const {
    cout << "\n--- RÈGLES ACTIVES ---" << endl;
    if (activeRules.empty()) {
        cout << "Aucune règle active détectée." << endl;
        return;
    }

    for (const Rule& rule : activeRules) {
        if (static_cast<int>(rule.properties) != 0) {
            cout << static_cast<int>(rule.subjects) << " " << static_cast<int>(rule.operators) << " " << static_cast<int>(rule.properties) << endl;
            continue;
        } else if (static_cast<int>(rule.transformation) != 0) {
            cout << static_cast<int>(rule.subjects) << " " << static_cast<int>(rule.operators) << " " << static_cast<int>(rule.transformation) << endl;
        }
    }
    cout << "----------------------\n" << endl;
}

void RuleEngine::updateRules() {
    clearActiveRules();
    for (Entity* nounEntity: map.getNounsTextOnMap()) {
        int x = nounEntity->getX();
        int y = nounEntity->getY();
        
        checkRules(x, y, nounEntity, true);
        checkRules(x, y, nounEntity, false);
    }
}

void RuleEngine::checkRules(const int x, const int y, const Entity* nounEntity, const bool isHorizontal) {
    int dx = isHorizontal ? 1 : 0;
    int dy = isHorizontal ? 0 : 1;
    if ((x + 2 * dx >= map.getWidth()) || (y + 2 * dy >= map.getHeight())) {
        return;
    }
    
    // Check si y'a un opérateur
    int xOp = x + dx;
    int yOp = y + dy;
    const Cell& cellOp = map.getCell(xOp, yOp);
    const std::vector<Entity*>& entitiesOp = cellOp.getEntities();
    if (entitiesOp.empty() || !entitiesOp[0]->isOperatorWordEntity()) {
        return;
    }

    // Check si y'a une propriété ou un nom
    int xTarget = x + 2 * dx;
    int yTarget = y + 2 * dy;
    const Cell& cellTarget = map.getCell(xTarget, yTarget);
    const std::vector<Entity*>& entitiesTarget = cellTarget.getEntities();
    if (entitiesTarget.empty()) {
        return;
    }

    Entity* targetEntity = entitiesTarget[0];
    if (targetEntity->isPropertyWordEntity()) {
        addActiveRule(
            nounEntity->getNounWordEntity(),
            entitiesOp[0]->getOperatorWordEntity(),
            targetEntity->getPropertyWordEntity(),
            NounWordEntity::NONE
        );
    } else if (targetEntity->isNounWordEntity()) {
        addActiveRule(
            nounEntity->getNounWordEntity(),
            entitiesOp[0]->getOperatorWordEntity(),
            PropertyWordEntity::NONE,
            targetEntity->getNounWordEntity()
        );
    }
}