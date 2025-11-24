#include "model/rule.hpp"

void Rule::addActiveRule(NounType nounType, PropertyType propertyType, NounType transformationTarget) {
    activeRules[nounType].properties.insert(propertyType);
    activeRules[nounType].transformationTargets.insert(transformationTarget);
}

map<NounType, Rule::PropertyRules> Rule::getActiveRules() const {
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

    for (const auto& pair : activeRules) {
        NounType subject = pair.first;
        const auto& ruleData = pair.second;
        
        for (PropertyType prop : ruleData.properties) {
            cout << static_cast<int>(subject) << " IS " << static_cast<int>(prop) << endl;
        }

        for (NounType target : ruleData.transformationTargets) {
            cout << static_cast<int>(subject) << " IS " << static_cast<int>(target) << " (Noun)" << endl;
        }
    }
    cout << "----------------------\n" << endl;
}