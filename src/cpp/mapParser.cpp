#include "../hpp/mapParser.hpp"

MapParser& MapParser::getInstance() {
    static MapParser instance;
    return instance;
}

void MapParser::parseConfig(const string path) {
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
    cout << mapData["map_name"] << " width: " << mapData["size"]["width"] << " height: " << mapData["size"]["height"] << endl;
    if (mapData.contains("walls") && mapData["walls"].is_array()) {
        for (json& wall : mapData["walls"]) {
            cout << "Wall(x,y) = (" << wall["x"] << "," << wall["y"]  << ")" << endl;
        }
    } else {
        cout << "No walls" << endl;
    }
}

const json& MapParser::getMapData() const {
    return mapData;
}
