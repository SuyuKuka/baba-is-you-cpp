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
    KEY.loadFromFile(path + "KEY.png");
    KEY_TEXT.loadFromFile(path + "KEY_TEXT.png");
    DOOR.loadFromFile(path + "DOOR.png");
    DOOR_TEXT.loadFromFile(path + "DOOR_TEXT.png");
    OPEN_TEXT.loadFromFile(path + "OPEN_TEXT.png");
    SHUT_TEXT.loadFromFile(path + "SHUT_TEXT.png");
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
        case 14: return DOOR;
        case 15: return KEY;
        case 30: return BABA_TEXT;
        case 31: return FLAG_TEXT;
        case 32: return ROCK_TEXT;
        case 33: return WALL_TEXT;
        case 34: return DOOR_TEXT;
        case 35: return KEY_TEXT;
        case 50: return IS_TEXT;
        case 70: return YOU_TEXT;
        case 71: return WIN_TEXT;
        case 72: return PUSH_TEXT;
        case 73: return STOP_TEXT;
        case 74: return PULL_TEXT;
        case 75: return OPEN_TEXT;
        case 76: return SHUT_TEXT;
        default: return BABA_RIGHT;
    }
}