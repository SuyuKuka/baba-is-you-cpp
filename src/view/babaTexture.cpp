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
        case 100:
            if (key == Keyboard::Q || key == Keyboard::Key::A) {
                return BABA_LEFT;
            } else if (key == Keyboard::S) {
                return BABA_DOWN;
            } else if (key == Keyboard::Key::Z || key == Keyboard::Key::W) {
                return BABA_UP;
            } 
        return BABA_RIGHT;
        case 101: return FLAG;
        case 102: return ROCK;
        case 103: return WALL;
        case 104: return DOOR;
        case 105: return KEY;
        case 200: return BABA_TEXT;
        case 201: return FLAG_TEXT;
        case 202: return ROCK_TEXT;
        case 203: return WALL_TEXT;
        case 204: return DOOR_TEXT;
        case 205: return KEY_TEXT;
        case 300: return IS_TEXT;
        case 400: return YOU_TEXT;
        case 401: return WIN_TEXT;
        case 402: return PUSH_TEXT;
        case 403: return STOP_TEXT;
        case 404: return PULL_TEXT;
        case 405: return SHUT_TEXT;
        case 406: return OPEN_TEXT;
        default: return BABA_RIGHT;
    }
}