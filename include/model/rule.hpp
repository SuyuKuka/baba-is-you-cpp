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
        NounText subjects;
        OperatorText operators;
        PropertyText properties; 
        NounText transformationTargets; 
    };

    vector<PropertyRules> activeRules;
public:
    Rule() = default;

    void addActiveRule(NounText nounText, OperatorText operatorText, PropertyText propertyText, NounText transformationTarget);
    vector<PropertyRules> getActiveRules() const;
    void clearActiveRules();
    void printActivesRules() const;
};

#endif