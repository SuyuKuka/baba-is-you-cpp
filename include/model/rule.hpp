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
    vector<TextNoun> nouns;
    vector<TextOperator> operators;
    vector<TextProperty> properties;
    struct PropertyRules {
        set<PropertyType> properties; 
        set<NounType> transformationTargets; 
    };

    map<NounType, PropertyRules> activeRules;
public:
    Rule() = default;
    
    void addNoun(TextNoun noun);
    void addOperator(TextOperator op);
    void addProperty(TextProperty prop);
    vector<TextNoun> getNouns() const;
    vector<TextOperator> getOperators() const;
    vector<TextProperty> getProperties() const;
    void clear();
    void printRule();
};

#endif