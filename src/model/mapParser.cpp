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

    MapParser::loadEntity(map, parser, "baba");
    MapParser::loadEntity(map, parser, "flag");
    MapParser::loadEntity(map, parser, "wall");

    MapParser::loadEntity(map, parser, "text_baba");
    MapParser::loadEntity(map, parser, "text_is");
    MapParser::loadEntity(map, parser, "text_you");
    MapParser::loadEntity(map, parser, "text_flag");
    MapParser::loadEntity(map, parser, "text_win");
    MapParser::loadEntity(map, parser, "text_wall");
    MapParser::loadEntity(map, parser, "text_stop");

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