#ifndef ENTITY_TYPE_HPP
#define ENTITY_TYPE_HPP

enum class NounType {
    BABA = 10,
    FLAG = 11,
    ROCK = 12,
    WALL = 13
};

enum class OperatorType {
    IS = 14,
};

enum class PropertyType {
    YOU = 15,
    WIN = 16,
    PUSH = 17,
    STOP = 18
};

enum class NounText {
    TEXTBABA = 19,
    TEXTFLAG = 20,
    TEXTROCK = 21,
    TEXTWALL = 22
};

enum class OperatorText {
    TEXTIS = 23
};

enum class PropertyText {
    TEXTYOU = 24,
    TEXTWIN = 25,
    TEXTPUSH = 26,
    TEXTSTOP = 27
};

#endif