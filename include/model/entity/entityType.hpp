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
    TEXTBABA = 19,
    TEXTFLAG = 20,
    TEXTROCK = 21,
    TEXTWALL = 22
};

enum class OperatorWordEntity {
    NONE = 0,
    TEXTIS = 23
};

enum class PropertyWordEntity {
    NONE = 0,
    TEXTYOU = 24,
    TEXTWIN = 25,
    TEXTPUSH = 26,
    TEXTSTOP = 27
};

#endif