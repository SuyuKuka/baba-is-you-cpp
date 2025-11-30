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


Map MapParser::loadMap(const string& path) {
    json parser = MapParser::parseJSON(path);
    Map map = Map(parser["width"], parser["height"]);
    RuleEngine& rules = map.getRuleEngine();

    for (json::iterator it = parser.begin(); it != parser.end(); ++it) {
        string key = it.key();
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
            const int x = location["x"];
            const int y = location["y"];
            const Position pos(x, y);

            if (entity == "walls") {
                Entity* wall = new EntityGame(pos, static_cast<int>(GameEntity::WALL));
                map.addCell(pos, wall);
                map.addNounEntityOnMap(wall);
            } else if (entity == "baba") {
                Entity* baba = new EntityGame(pos, static_cast<int>(GameEntity::BABA));
                map.addCell(pos, baba);
                map.addNounEntityOnMap(baba);
            } else if (entity == "flag") {
                Entity* flag = new EntityGame(pos, static_cast<int>(GameEntity::FLAG));
                map.addCell(pos, flag);
                map.addNounEntityOnMap(flag);
            } else if (entity == "rock") {
                Entity* rock = new EntityGame(pos, static_cast<int>(GameEntity::ROCK));
                map.addCell(pos, rock);
                map.addNounEntityOnMap(rock);
            } else if (entity == "text_baba") {
                Entity* text_baba = new EntityNoun(pos, static_cast<int>(NounWordEntity::TEXTBABA));
                map.addCell(pos, text_baba);
                map.addNounTextOnMap(text_baba);
            } else if (entity == "text_flag") {
                Entity* text_flag = new EntityNoun(pos, static_cast<int>(NounWordEntity::TEXTFLAG));
                map.addCell(pos, text_flag);
                map.addNounTextOnMap(text_flag);
            } else if (entity == "text_rock") {
                Entity* text_rock = new EntityNoun(pos, static_cast<int>(NounWordEntity::TEXTROCK));
                map.addCell(pos, text_rock);
                map.addNounTextOnMap(text_rock);
            } else if (entity == "text_wall") {
                Entity* text_wall = new EntityNoun(pos, static_cast<int>(NounWordEntity::TEXTWALL));
                map.addCell(pos, text_wall);
                map.addNounTextOnMap(text_wall);
            } else if (entity == "text_is") {
                Entity* text_is = new EntityOperator(pos, static_cast<int>(OperatorWordEntity::TEXTIS));
                map.addCell(pos, text_is);
            } else if (entity == "text_you") {
                Entity* text_you = new EntityProperty(pos, static_cast<int>(PropertyWordEntity::TEXTYOU));
                map.addCell(pos, text_you);
            } else if (entity == "text_win") {
                Entity* text_win = new EntityProperty(pos, static_cast<int>(PropertyWordEntity::TEXTWIN));
                map.addCell(pos, text_win);
            } else if (entity == "text_push") {
                Entity* text_push = new EntityProperty(pos, static_cast<int>(PropertyWordEntity::TEXTPUSH));
                map.addCell(pos, text_push);
            } else if (entity == "text_stop") {
                Entity* text_stop = new EntityProperty(pos, static_cast<int>(PropertyWordEntity::TEXTSTOP));
                map.addCell(pos, text_stop);
            } else {
                cout << "Unknown entity: " << entity << endl;
            }
        }
    }
}