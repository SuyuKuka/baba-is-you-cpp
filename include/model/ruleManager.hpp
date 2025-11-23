#ifndef RULEMANAGER_HPP
#define RULEMANAGER_HPP
#include "model/map.hpp"
#include <variant>
#include <map>
#include <set>

class RuleManager {
private:
    std::map<NounType, std::set<PropertyType>> activeRules;
public:
    void updateRules(Map& map);
};

#endif