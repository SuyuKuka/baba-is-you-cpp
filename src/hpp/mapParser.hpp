#ifndef _MAPPARSER
#define _MAPPARSER
#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

/**
 * @class mapParser 
 * @brief Utiliser pour récupérer la config de la carte depuis un json.
 */
class MapParser {
    private:
    json mapData;
    MapParser() = default;
    ~MapParser() = default;
    MapParser(const MapParser&) = delete;
    MapParser& operator=(const MapParser&) = delete;
    public:
    static MapParser& getInstance();
    void parseConfig(const string path);
};

#endif