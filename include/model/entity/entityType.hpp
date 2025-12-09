#ifndef ENTITY_TYPE_HPP
#define ENTITY_TYPE_HPP

enum class GameEntity {
    NONE = 0,
    BABA = 100,
    FLAG = 101,
    ROCK = 102,
    WALL = 103,
    DOOR = 104,
    KEY = 105
};

enum class NounWordEntity {
    TEXTBABA = 200,
    TEXTFLAG = 201,
    TEXTROCK = 202,
    TEXTWALL = 203,
    TEXTDOOR = 204,
    TEXTKEY = 205
};

enum class OperatorWordEntity {
    TEXTIS = 300,
    TEXTAND = 301
};

enum class PropertyWordEntity {
    TEXTYOU = 400,
    TEXTWIN = 401,
    TEXTPUSH = 402,
    TEXTSTOP = 403,
    TEXTPULL = 404,
    TEXTSHUT = 405,
    TEXTOPEN = 406,
};

#endif