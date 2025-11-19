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

enum class RuleType {
    TEXTBABA = 19,
    TEXTFLAG = 20,
    TEXTROCK = 21,
    TEXTWALL = 22,
    TEXTIS = 23,
    TEXTYOU = 24,
    TEXTWIN = 25,
    TEXTPUSH = 26,
    TEXTSTOP = 27
};

#endif