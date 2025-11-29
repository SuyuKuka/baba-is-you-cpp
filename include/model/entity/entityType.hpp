#ifndef ENTITY_TYPE_HPP
#define ENTITY_TYPE_HPP

enum class GameEntity {
    BABA = 10,
    FLAG = 11,
    ROCK = 12,
    WALL = 13
};

enum class NounWordEntity {
    NONE = 0,
    TEXTBABA = 14,
    TEXTFLAG = 15,
    TEXTROCK = 16,
    TEXTWALL = 17
};

enum class OperatorWordEntity {
    NONE = 0,
    TEXTIS = 18
};

enum class PropertyWordEntity {
    NONE = 0,
    TEXTYOU = 19,
    TEXTWIN = 20,
    TEXTPUSH = 21,
    TEXTSTOP = 22,
    TEXTPULL = 23
};

#endif