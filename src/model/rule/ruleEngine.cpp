#include "model/rule/ruleEngine.hpp"
#include "model/mainModel.hpp"

void RuleEngine::addActiveRule(const NounWordEntity noun, const OperatorWordEntity ope, const PropertyWordEntity property, const NounWordEntity transform) {
    Rule rule;
    rule.subjects = noun;
    rule.operators = ope;
    rule.properties = property;
    rule.transformation = transform;
    activeRules.push_back(rule);
}

const vector<Rule>& RuleEngine::getActiveRules() const {
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
    // Reset le pushable de tous les entités
    for (Entity* entity: game.getMap()->getNounsEntityOnMap()) {
        entity->setPushable(false);
    }

    for (Entity* nounEntity: game.getMap()->getNounsTextOnMap()) {
        Position pos = nounEntity->getPosition();
        
        checkRules(pos, nounEntity, true);
        checkRules(pos, nounEntity, false);
    }
}

void RuleEngine::checkRules(Position pos, const Entity* nounEntity, const bool isHorizontal) {
    int dx = isHorizontal ? 1 : 0;
    int dy = isHorizontal ? 0 : 1;
    if ((pos.x + 2 * dx >= game.getMap()->getWidth()) || (pos.y + 2 * dy >= game.getMap()->getHeight())) {
        return;
    }
    
    // Check si y'a un opérateur
    Position posOp(pos.x + dx, pos.y + dy);
    const Cell& cellOp = (*game.getMap())[posOp];
    const vector<Entity*>& entitiesOp = cellOp.getEntities();
    if (entitiesOp.empty() || !entitiesOp[0]->isOperatorWordEntity()) {
        return;
    }

    // Check si y'a une propriété ou un nom
    Position posTarget(pos.x + 2 * dx, pos.y + 2 * dy);
    const Cell& cellTarget = (*game.getMap())[posTarget];
    const vector<Entity*>& entitiesTarget = cellTarget.getEntities();
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