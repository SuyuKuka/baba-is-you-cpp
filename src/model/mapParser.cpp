#include "model/mapParser.hpp"

json MapParser::parseJSON(const string path) {
    json mapData;
    try {
        ifstream file(path);
        if (!file.is_open()) {
            throw invalid_argument("File not found.");
        }
        file >> mapData;
    } catch (const invalid_argument& ia) {
        cout << ia.what() << endl;
        exit(EXIT_FAILURE);
    }
    return mapData;
}


Map MapParser::loadMap(const std::string& path) {
    json parser = MapParser::parseJSON(path);
    Map map = Map(parser["width"], parser["height"]);

    for (json::iterator it = parser.begin(); it != parser.end(); ++it) {
        std::string key = it.key();
        if (key == "map_name" || key == "width" || key == "height") {
            continue;
        }
        std::cout << "  - " << key << std::endl;
        loadEntity(map, parser, key);
    }

    map.printMap();

    return map;
}

void MapParser::loadEntity(Map map, json parser, string entity) {
    if (parser.contains(entity) && parser[entity].is_array()) {
        for (json& entity : parser[entity]) {
            int x = entity["x"];
            int y = entity["y"];
           
            if (entity["type"] == "wall") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::WALL));
            } else if (entity["type"] == "baba") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::BABA));
            } else if (entity["type"] == "flag") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::FLAG));
            }
        }
    }
}