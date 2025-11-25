#ifndef RULE_HPP
#define RULE_HPP
#include "model/entity/entityNoun.hpp"
#include "model/entity/entityOperator.hpp"
#include "model/entity/entityProperty.hpp"
#include "model/entity/entityType.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Rule {
public:
    NounWordEntity subjects;
    OperatorWordEntity operators;
    PropertyWordEntity properties; 
    NounWordEntity transformation; 
};

#endif