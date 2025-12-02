#ifndef MAP_PARSER_HPP
#define MAP_PARSER_HPP
#include <iostream>
#include <fstream>
#include "model/map/json.hpp"
#include "model/map/position.hpp"
#include "model/rule/ruleEngine.hpp"
#include "model/entity/entityGame.hpp"
#include "model/entity/entityNoun.hpp"
#include "model/entity/entityOperator.hpp"
#include "model/entity/entityProperty.hpp"
#include "model/entity/entityType.hpp"

using namespace std;
using json = nlohmann::json;

class Map;

/**
 * @class mapParser 
 * @brief Utiliser pour récupérer la config de la carte depuis un json.
 */
class MapParser {
private:
    MapParser() = delete;
    static json parseJSON(const string path);
    static void loadEntity(Map& map, const json parser, const string entity);
    static void loadGameEntity(Map& map, const string entity, const Position& pos);
    static void loadNounText(Map& map, const string entity, const Position& pos);
    static void loadOperatorText(Map& map, const string entity, const Position& pos);
    static void loadPropertyText(Map& map, const string entity, const Position& pos);

public:
    static Map loadMap(const string& path);
};

#endif