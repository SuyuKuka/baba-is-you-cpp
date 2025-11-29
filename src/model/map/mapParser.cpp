#include "model/map/mapParser.hpp"

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
    RuleEngine& rules = map.getRuleEngine();
    RuleProcessor& ruleProcessor = map.getRuleProcessor();

    for (json::iterator it = parser.begin(); it != parser.end(); ++it) {
        std::string key = it.key();
        if (key == "map_name" || key == "width" || key == "height") {
            continue;
        }
        loadEntity(map, parser, key);
    }
    rules.updateRules();
    return map;
}

void MapParser::loadEntity(Map& map, json parser, string entity) {
    if (parser.contains(entity) && parser[entity].is_array()) {
        for (json& location : parser[entity]) {
            int x = location["x"];
            int y = location["y"];
           
            if (entity == "walls") {
                Entity* wall = new EntityGame(x, y, static_cast<int>(GameEntity::WALL));
                map.addCell(x, y, wall);
                map.addNounEntityOnMap(wall);
            } else if (entity == "baba") {
                Entity* baba = new EntityGame(x, y, static_cast<int>(GameEntity::BABA));
                map.addCell(x, y, baba);
                map.addNounEntityOnMap(baba);
            } else if (entity == "flag") {
                Entity* flag = new EntityGame(x, y, static_cast<int>(GameEntity::FLAG));
                map.addCell(x, y, flag);
                map.addNounEntityOnMap(flag);
            } else if (entity == "rock") {
                Entity* rock = new EntityGame(x, y, static_cast<int>(GameEntity::ROCK));
                map.addCell(x, y, rock);
                map.addNounEntityOnMap(rock);
            } else if (entity == "text_baba") {
                Entity* text_baba = new EntityNoun(x, y, static_cast<int>(NounWordEntity::TEXTBABA));
                map.addCell(x, y, text_baba);
                map.addNounTextOnMap(text_baba);
            } else if (entity == "text_flag") {
                Entity* text_flag = new EntityNoun(x, y, static_cast<int>(NounWordEntity::TEXTFLAG));
                map.addCell(x, y, text_flag);
                map.addNounTextOnMap(text_flag);
            } else if (entity == "text_rock") {
                Entity* text_rock = new EntityNoun(x, y, static_cast<int>(NounWordEntity::TEXTROCK));
                map.addCell(x, y, text_rock);
                map.addNounTextOnMap(text_rock);
            } else if (entity == "text_wall") {
                Entity* text_wall = new EntityNoun(x, y, static_cast<int>(NounWordEntity::TEXTWALL));
                map.addCell(x, y, text_wall);
                map.addNounTextOnMap(text_wall);
            } else if (entity == "text_is") {
                Entity* text_is = new EntityOperator(x, y, static_cast<int>(OperatorWordEntity::TEXTIS));
                map.addCell(x, y, text_is);
            } else if (entity == "text_you") {
                Entity* text_you = new EntityProperty(x, y, static_cast<int>(PropertyWordEntity::TEXTYOU));
                map.addCell(x, y, text_you);
            } else if (entity == "text_win") {
                Entity* text_win = new EntityProperty(x, y, static_cast<int>(PropertyWordEntity::TEXTWIN));
                map.addCell(x, y, text_win);
            } else if (entity == "text_push") {
                Entity* text_push = new EntityProperty(x, y, static_cast<int>(PropertyWordEntity::TEXTPUSH));
                map.addCell(x, y, text_push);
            } else if (entity == "text_stop") {
                Entity* text_stop = new EntityProperty(x, y, static_cast<int>(PropertyWordEntity::TEXTSTOP));
                map.addCell(x, y, text_stop);
            } else {
                std::cout << "Unknown entity: " << entity << std::endl;
            }
        }
    }
}