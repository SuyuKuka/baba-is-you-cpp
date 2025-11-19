#ifndef _MAPPARSER
#define _MAPPARSER
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "model/map.hpp"
#include "model/entity/entityNoun.hpp"
#include "model/entity/entityOperator.hpp"
#include "model/entity/entityProperty.hpp"
#include "model/entity/entityRule.hpp"
#include "model/entity/entityType.hpp"

using namespace std;
using json = nlohmann::json;

/**
 * @class mapParser 
 * @brief Utiliser pour récupérer la config de la carte depuis un json.
 */
class MapParser {
private:
    MapParser() = delete;
    static json parseJSON(const string path);
    static void loadEntity(Map& map, const json parser, const string entity);

public:
    static Map loadMap(const std::string& path);
};

#endif