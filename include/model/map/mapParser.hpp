#ifndef MAP_PARSER_HPP
#define MAP_PARSER_HPP
#include <iostream>
#include <fstream>
#include "json.hpp"
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
    MapParser() = default;
    json parseJSON(const string path);
    void loadEntity(Map& map, const json parser, const string entity);
    void loadGameEntity(Map& map, const string entity, const Position& pos);
    void loadNounText(Map& map, const string entity, const Position& pos);
    void loadOperatorText(Map& map, const string entity, const Position& pos);
    void loadPropertyText(Map& map, const string entity, const Position& pos);

public:
    MapParser(const MapParser&) = delete;
    void operator=(const MapParser&) = delete;
    static MapParser& getInstance();
    Map loadMap(const string& path);
};

#endif