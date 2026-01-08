#include "view/babaTexture.hpp"

/** 
 * Constructeur de BabaTexture.
 * Les textures de BABA ne sont pas dans la map.
*/
BabaTexture::BabaTexture() {
    BABA_UP.loadFromFile(path + "BABA_UP.png");
    BABA_RIGHT.loadFromFile(path + "BABA_RIGHT.png");
    BABA_LEFT.loadFromFile(path + "BABA_LEFT.png");
    BABA_DOWN.loadFromFile(path + "BABA_DOWN.png");
    BABA_TEXT.loadFromFile(path + "BABA_TEXT.png");
    last_baba_texture = &BABA_RIGHT;

    json spritesData;
    try {
        ifstream file(texture_config);
        if (!file.is_open()) {
            throw invalid_argument("File not found.");
        }
        file >> spritesData;
    } catch (const invalid_argument& ia) {
        cout << ia.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (spritesData.contains("sprites") && spritesData["sprites"].is_array()) {
        for (json& entries : spritesData["sprites"]) {
            const int id = entries["id"];
            const string sprite = entries["sprite"];
            Texture tmp;
            tmp.loadFromFile(path + sprite);
            textures.emplace(id, tmp);
        }
    }
}

BabaTexture& BabaTexture::getInstance() {
    static BabaTexture instance;
    return instance;
}

const Texture& BabaTexture::getTexture(const int& id,  const Direction& dir) {
    if (id == static_cast<int>(GameEntity::BABA)) {
        if (dir == Direction::WEST || dir == Direction::WEST) {
                last_baba_texture = &BABA_LEFT;
                return BABA_LEFT;
            } else if (dir == Direction::SOUTH) {
                last_baba_texture = &BABA_DOWN; 
                return BABA_DOWN;
            } else if (dir == Direction::NORTH || dir == Direction::NORTH) {
                last_baba_texture = &BABA_UP;
                return BABA_UP;
            } else if (dir == Direction::EAST) {
                last_baba_texture = &BABA_RIGHT;
                return BABA_RIGHT;
            }
        return *last_baba_texture;
    } else {
        return textures[id];
    }
}

void BabaTexture::resetLastTexutre() {
    last_baba_texture = &BABA_RIGHT;
}