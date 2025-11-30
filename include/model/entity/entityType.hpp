#ifndef ENTITY_TYPE_HPP
#define ENTITY_TYPE_HPP

enum class GameEntity {
    BABA = 10,
    FLAG = 11,
    ROCK = 12,
    WALL = 13,
    DOOR = 14,
    KEY = 15
};

enum class NounWordEntity {
    NONE = 0,
    TEXTBABA = 30,
    TEXTFLAG = 31,
    TEXTROCK = 32,
    TEXTWALL = 33,
    TEXTDOOR = 34,
    TEXTKEY = 35
};

enum class OperatorWordEntity {
    NONE = 0,
    TEXTIS = 50
};

enum class PropertyWordEntity {
    NONE = 0,
    TEXTYOU = 70,
    TEXTWIN = 71,
    TEXTPUSH = 72,
    TEXTSTOP = 73,
    TEXTPULL = 74,
    TEXTOPEN = 75,
    TEXTSHUT = 76
};

#endif