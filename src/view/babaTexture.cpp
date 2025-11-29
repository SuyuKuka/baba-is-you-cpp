#include "view/babaTexture.hpp"

BabaTexture::BabaTexture() {
    BABA_UP.loadFromFile(path + "BABA_UP.png");
    BABA_RIGHT.loadFromFile(path + "BABA_RIGHT.png");
    BABA_LEFT.loadFromFile(path + "BABA_LEFT.png");
    BABA_DOWN.loadFromFile(path + "BABA_DOWN.png");
    BABA_TEXT.loadFromFile(path + "BABA_TEXT.png");
    FLAG_TEXT.loadFromFile(path + "FLAG_TEXT.png");
    FLAG.loadFromFile(path + "FLAG.png");
    IS_TEXT.loadFromFile(path + "IS.png");
    PULL_TEXT.loadFromFile(path + "PULL.png");
    PUSH_TEXT.loadFromFile(path + "PUSH.png");
    ROCK_TEXT.loadFromFile(path + "ROCK_TEXT.png");
    ROCK.loadFromFile(path + "ROCK.png");
    STOP_TEXT.loadFromFile(path + "STOP.png");
    WALL_TEXT.loadFromFile(path + "WALL_TEXT.png");
    WALL.loadFromFile(path + "WALL.png");
    WIN_TEXT.loadFromFile(path + "WIN.png");
    YOU_TEXT.loadFromFile(path + "YOU.png");
}

BabaTexture& BabaTexture::getInstance() {
    static BabaTexture instance;
    return instance;
}

const Texture& BabaTexture::getTexture(const int id,  const Keyboard::Key key) const {
    switch (id) {
        case 10:
            if (key == Keyboard::Q || key == Keyboard::Key::A) {
                return BABA_LEFT;
            } else if (key == Keyboard::S) {
                return BABA_DOWN;
            } else if (key == Keyboard::Key::Z || key == Keyboard::Key::W) {
                return BABA_UP;
            } 
        return BABA_RIGHT;
        case 11: return FLAG;
        case 12: return ROCK;
        case 13: return WALL;
        case 14: return BABA_TEXT;
        case 15: return FLAG_TEXT;
        case 16: return ROCK_TEXT;
        case 17: return WALL_TEXT;
        case 18: return IS_TEXT;
        case 19: return YOU_TEXT;
        case 20: return WIN_TEXT;
        case 21: return PUSH_TEXT;
        case 22: return STOP_TEXT;
        case 23: return PULL_TEXT;
        default: return BABA_RIGHT;
    }
}