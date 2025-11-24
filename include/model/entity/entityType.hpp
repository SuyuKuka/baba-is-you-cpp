#ifndef ENTITY_TYPE_HPP
#define ENTITY_TYPE_HPP

enum class NounType {
    NONE = 0,
    BABA = 10,
    FLAG = 11,
    ROCK = 12,
    WALL = 13
};

enum class OperatorType {
    NONE = 0,
    IS = 14,
};

enum class PropertyType {
    NONE = 0,
    YOU = 15,
    WIN = 16,
    PUSH = 17,
    STOP = 18
};

enum class NounText {
    NONE = 0,
    TEXTBABA = 19,
    TEXTFLAG = 20,
    TEXTROCK = 21,
    TEXTWALL = 22
};

enum class OperatorText {
    NONE = 0,
    TEXTIS = 23
};

enum class PropertyText {
    NONE = 0,
    TEXTYOU = 24,
    TEXTWIN = 25,
    TEXTPUSH = 26,
    TEXTSTOP = 27
};

#endif