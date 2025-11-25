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
    Rule rules = Rule();

    for (json::iterator it = parser.begin(); it != parser.end(); ++it) {
        std::string key = it.key();
        if (key == "map_name" || key == "width" || key == "height") {
            continue;
        }
        std::cout << "  - " << key << std::endl;
        loadEntity(map, parser, key);
    }
    map.printMap();
    map.updateRules();
    map.printRules();
    return map;
}

void MapParser::loadEntity(Map& map, json parser, string entity) {
    if (parser.contains(entity) && parser[entity].is_array()) {
        for (json& location : parser[entity]) {
            int x = location["x"];
            int y = location["y"];
           
            std::cout << "x: " << x << ", y: " << y << std::endl;
            if (entity == "walls") {
                Entity* wall = new EntityNoun(x, y, static_cast<int>(NounType::WALL));
                map.addCell(x, y, wall);
            } else if (entity == "baba") {
                Entity* baba = new EntityNoun(x, y, static_cast<int>(NounType::BABA));
                map.addCell(x, y, baba);
            } else if (entity == "flag") {
                map.addCell(x, y, new EntityNoun(x, y, static_cast<int>(NounType::FLAG)));
            } else if (entity == "rock") {
                map.addCell(x, y, new EntityNoun(x, y, static_cast<int>(NounType::ROCK)));
            } else if (entity == "is") {
                map.addCell(x, y, new EntityOperator(x, y, static_cast<int>(OperatorType::IS)));
            } else if (entity == "you") {
                map.addCell(x, y, new EntityProperty(x, y, static_cast<int>(PropertyType::YOU)));
            } else if (entity == "win") {
                map.addCell(x, y, new EntityProperty(x, y, static_cast<int>(PropertyType::WIN)));
            } else if (entity == "push") {
                map.addCell(x, y, new EntityProperty(x, y, static_cast<int>(PropertyType::PUSH)));
            } else if (entity == "stop") {
                map.addCell(x, y, new EntityProperty(x, y, static_cast<int>(PropertyType::STOP)));
            } else if (entity == "text_baba") {
                map.addCell(x, y, new TextNoun(x, y, static_cast<int>(NounText::TEXTBABA)));
                map.addNoun(new TextNoun(x, y, static_cast<int>(NounText::TEXTBABA)));
            } else if (entity == "text_flag") {
                map.addCell(x, y, new TextNoun(x, y, static_cast<int>(NounText::TEXTFLAG)));
                map.addNoun(new TextNoun(x, y, static_cast<int>(NounText::TEXTFLAG)));
            } else if (entity == "text_rock") {
                map.addCell(x, y, new TextNoun(x, y, static_cast<int>(NounText::TEXTROCK)));
                map.addNoun(new TextNoun(x, y, static_cast<int>(NounText::TEXTROCK)));
            } else if (entity == "text_wall") {
                map.addCell(x, y, new TextNoun(x, y, static_cast<int>(NounText::TEXTWALL)));
                map.addNoun(new TextNoun(x, y, static_cast<int>(NounText::TEXTWALL)));
            } else if (entity == "text_is") {
                map.addCell(x, y, new TextOperator(x, y, static_cast<int>(OperatorText::TEXTIS)));
            } else if (entity == "text_you") {
                map.addCell(x, y, new TextProperty(x, y, static_cast<int>(PropertyText::TEXTYOU)));
            } else if (entity == "text_win") {
                map.addCell(x, y, new TextProperty(x, y, static_cast<int>(PropertyText::TEXTWIN)));
            } else if (entity == "text_push") {
                map.addCell(x, y, new TextProperty(x, y, static_cast<int>(PropertyText::TEXTPUSH)));
            } else if (entity == "text_stop") {
                map.addCell(x, y, new TextProperty(x, y, static_cast<int>(PropertyText::TEXTSTOP)));
            } else {
                std::cout << "Unknown entity: " << entity << std::endl;
            }
        }
    }
}