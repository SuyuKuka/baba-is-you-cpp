#ifndef RULE_HPP
#define RULE_HPP
#include "model/entity/entityType.hpp"

struct Rule {
    NounWordEntity subjects;
    OperatorWordEntity operators;
    PropertyWordEntity properties; 
    NounWordEntity transformation; 
};

#endif