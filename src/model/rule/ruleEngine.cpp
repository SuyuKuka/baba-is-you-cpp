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
        entity->setPullable(false);
    }

    for (Entity* nounEntity: game.getMap()->getNounsTextOnMap()) {
        Position pos = nounEntity->getPosition();
        
        checkRules(pos, nounEntity, true);
        checkRules(pos, nounEntity, false);
    }
}

void RuleEngine::checkRules(Position pos, Entity* nounEntity, const bool isHorizontal) {
    int dx = isHorizontal ? 1 : 0;
    int dy = isHorizontal ? 0 : 1;
    if ((pos.x + 2 * dx >= game.getMap()->getWidth()) || (pos.y + 2 * dy >= game.getMap()->getHeight())) {
        return;
    }

    entitiesNoun.push_back(nounEntity);
    Position posOp(pos.x + dx, pos.y + dy);
    Position posTarget(pos.x + 2 * dx, pos.y + 2 * dy);
    Cell cellOp = (*game.getMap())[posOp];
    Cell cellTarget = (*game.getMap())[posTarget];

    while ((!cellOp.getEntities().empty() && (cellOp.hasOperatorEntity() != (size_t)-1)) 
        && (!cellTarget.getEntities().empty() && (cellTarget.hasPropertyEntity() != (size_t)-1 || cellTarget.hasNounEntity() != (size_t)-1))) {

        // Tant qu'on a une opérateur et une propriété ou un nom devant on l'ajoute dans la liste
        entitiesOp.push_back(cellOp.getEntities()[cellOp.hasOperatorEntity()]);
        entitiesTarget.push_back(cellTarget.getEntities()[cellTarget.hasPropertyEntity() != (size_t)-1 ? cellTarget.hasPropertyEntity() : cellTarget.hasNounEntity()]);

        posOp += Position(dx, dy);
        posTarget += Position(2 * dx, 2 * dy);
        cellOp = (*game.getMap())[posOp];
        cellTarget = (*game.getMap())[posTarget];
    }

    if (entitiesOp.empty() || entitiesTarget.empty()) {
        entitiesNoun.clear();
        entitiesOp.clear();
        entitiesTarget.clear();
        return;
    }

    for (Entity* entityOp: entitiesOp) {
        for (Entity* entityTarget: entitiesTarget) {
            if (entityTarget->isPropertyWordEntity()) {
                addActiveRule(nounEntity->getNounWordEntity(), entityOp->getOperatorWordEntity(), entityTarget->getPropertyWordEntity(), NounWordEntity::NONE);
            } else if (entityTarget->isNounWordEntity()) {
                addActiveRule(nounEntity->getNounWordEntity(), entityOp->getOperatorWordEntity(), PropertyWordEntity::NONE, entityTarget->getNounWordEntity());
            }
        }
    }

    entitiesNoun.clear();
    entitiesOp.clear();
    entitiesTarget.clear();
}