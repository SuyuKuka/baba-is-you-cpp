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

void MapParser::loadEntity(Map& map, json parser, string entity) {
    if (parser.contains(entity) && parser[entity].is_array()) {
        for (json& location : parser[entity]) {
            int x = location["x"];
            int y = location["y"];
           
            std::cout << "x: " << x << ", y: " << y << std::endl;
            if (entity == "walls") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::WALL));
            } else if (entity == "baba") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::BABA));
            } else if (entity == "flag") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::FLAG));
            } else if (entity == "rock") {
                map.addCell(x, y, new EntityNoun(x, y, NounType::ROCK));
            } else if (entity == "is") {
                map.addCell(x, y, new EntityOperator(x, y, OperatorType::IS));
            } else if (entity == "you") {
                map.addCell(x, y, new EntityProperty(x, y, PropertyType::YOU));
            } else if (entity == "win") {
                map.addCell(x, y, new EntityProperty(x, y, PropertyType::WIN));
            } else if (entity == "push") {
                map.addCell(x, y, new EntityProperty(x, y, PropertyType::PUSH));
            } else if (entity == "stop") {
                map.addCell(x, y, new EntityProperty(x, y, PropertyType::STOP));
            } else if (entity == "text_baba") {
                map.addCell(x, y, new TextNoun(x, y, NounText::TEXTBABA));
                map.addRule(Rule(x, y, NounText::TEXTBABA));
            } else if (entity == "text_flag") {
                map.addCell(x, y, new TextNoun(x, y, NounText::TEXTFLAG));
                map.addRule(Rule(x, y, NounText::TEXTFLAG));
            } else if (entity == "text_rock") {
                map.addCell(x, y, new TextNoun(x, y, NounText::TEXTROCK));
                map.addRule(Rule(x, y, NounText::TEXTROCK));
            } else if (entity == "text_wall") {
                map.addCell(x, y, new TextNoun(x, y, NounText::TEXTWALL));
                map.addRule(Rule(x, y, NounText::TEXTWALL));
            } else if (entity == "text_is") {
                map.addCell(x, y, new TextOperator(x, y, OperatorText::TEXTIS));
            } else if (entity == "text_you") {
                map.addCell(x, y, new TextProperty(x, y, PropertyText::TEXTYOU));
            } else if (entity == "text_win") {
                map.addCell(x, y, new TextProperty(x, y, PropertyText::TEXTWIN));
            } else if (entity == "text_push") {
                map.addCell(x, y, new TextProperty(x, y, PropertyText::TEXTPUSH));
            } else if (entity == "text_stop") {
                map.addCell(x, y, new TextProperty(x, y, PropertyText::TEXTSTOP));
            }
        }
    }
}