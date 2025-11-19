#ifndef _MAPPARSER
#define _MAPPARSER
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "model/map.hpp"
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
public:
    static Map loadMap(const std::string& path);
};

#endif