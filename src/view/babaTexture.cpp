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
    AND_TEXT.loadFromFile(path + "AND.png");
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
    last_baba_texture = &BABA_RIGHT;
}

BabaTexture& BabaTexture::getInstance() {
    static BabaTexture instance;
    return instance;
}

const Texture& BabaTexture::getTexture(const int& id,  const Direction& dir) {
    switch (id) {
        case 100:
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
        case static_cast<int>(GameEntity::FLAG): return FLAG;
        case static_cast<int>(GameEntity::ROCK): return ROCK;
        case static_cast<int>(GameEntity::WALL): return WALL;
        case static_cast<int>(GameEntity::DOOR): return DOOR;
        case static_cast<int>(GameEntity::KEY): return KEY;
        case static_cast<int>(NounWordEntity::TEXTBABA): return BABA_TEXT;
        case static_cast<int>(NounWordEntity::TEXTFLAG): return FLAG_TEXT;
        case static_cast<int>(NounWordEntity::TEXTROCK): return ROCK_TEXT;
        case static_cast<int>(NounWordEntity::TEXTWALL): return WALL_TEXT;
        case static_cast<int>(NounWordEntity::TEXTDOOR): return DOOR_TEXT;
        case static_cast<int>(NounWordEntity::TEXTKEY): return KEY_TEXT;
        case static_cast<int>(OperatorWordEntity::TEXTIS): return IS_TEXT;
        case static_cast<int>(OperatorWordEntity::TEXTAND): return AND_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTYOU): return YOU_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTWIN): return WIN_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTPUSH): return PUSH_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTSTOP): return STOP_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTPULL): return PULL_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTSHUT): return SHUT_TEXT;
        case static_cast<int>(PropertyWordEntity::TEXTOPEN): return OPEN_TEXT;
        default: return BABA_RIGHT;
    }
}

void BabaTexture::resetLastTexutre() {
    last_baba_texture = &BABA_RIGHT;
}