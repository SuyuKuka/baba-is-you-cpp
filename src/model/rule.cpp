#include "model/rule.hpp"

void Rule::addActiveRule(NounText nounType, OperatorText operatorType, PropertyText propertyType, NounText transformationTarget) {
    PropertyRules ruleData;
    ruleData.subjects = nounType;
    ruleData.operators = operatorType;
    ruleData.transformationTargets = transformationTarget;
    ruleData.properties = propertyType;
    activeRules.push_back(ruleData);
}

vector<Rule::PropertyRules> Rule::getActiveRules() const {
    return activeRules;
}

void Rule::clearActiveRules() {
    activeRules.clear();
}

void Rule::printActivesRules() const {
    cout << "\n--- RÈGLES ACTIVES ---" << endl;
    if (activeRules.empty()) {
        cout << "Aucune règle active détectée." << endl;
        return;
    }

    for (const auto& ruleData : activeRules) {
        if (static_cast<int>(ruleData.properties) != 0) {
            cout << static_cast<int>(ruleData.subjects) << " " << static_cast<int>(ruleData.operators) << " " << static_cast<int>(ruleData.properties) << endl;
            continue;
        } else if (static_cast<int>(ruleData.transformationTargets) != 0) {
            cout << static_cast<int>(ruleData.subjects) << " " << static_cast<int>(ruleData.operators) << " " << static_cast<int>(ruleData.transformationTargets) << endl;
        }
    }
    cout << "----------------------\n" << endl;
}