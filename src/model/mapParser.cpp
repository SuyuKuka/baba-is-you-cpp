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

    //TODO : Enlever les prints et créer des fonctions permettant de charger le niveau
    cout << mapData["map_name"] << " width: " << mapData["width"] << " height: " << mapData["height"] << endl;
    if (mapData.contains("walls") && mapData["walls"].is_array()) {
        for (json& wall : mapData["walls"]) {
            cout << "Wall(x,y) = (" << wall["x"] << "," << wall["y"]  << ")" << endl;
        }
    } else {
        cout << "No walls" << endl;
    }
    return mapData;
}


Map MapParser::loadMap(const std::string& path) {
    json parser = MapParser::parseJSON(path);
    return Map(parser["width"], parser["height"]);
}