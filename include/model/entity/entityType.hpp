#ifndef ENTITY_TYPE_HPP
#define ENTITY_TYPE_HPP

enum class NounType {
    NONE = 0,
    BABA,
    FLAG,
    ROCK,
    WALL
};

enum class OperatorType {
    NONE = 0,
    IS,
};

enum class PropertyType {
    NONE = 0,
    YOU,
    WIN,
    PUSH,
    STOP
};

enum class RuleType {
    TEXTBABA,
    TEXTFLAG,
    TEXTROCK,
    TEXTWALL,
    TEXTIS,
    TEXTYOU,
    TEXTWIN,
    TEXTPUSH,
    TEXTSTOP
};

#endif