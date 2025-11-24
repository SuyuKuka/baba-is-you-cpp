#ifndef RULE_HPP
#define RULE_HPP
#include "model/entity/entityType.hpp"
#include "model/entity/textNoun.hpp"
#include "model/entity/textOperator.hpp"
#include "model/entity/textProperty.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Rule {
private:
    struct PropertyRules {
        set<PropertyType> properties; 
        set<NounType> transformationTargets; 
    };

    map<NounType, PropertyRules> activeRules;
public:
    Rule() = default;

    void addActiveRule(NounType nounType, PropertyType propertyType, NounType transformationTarget);
    map<NounType, PropertyRules> getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;
};

#endif