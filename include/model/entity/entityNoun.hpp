#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityNoun: public Entity {
public:
    EntityNoun(Position pos, int id);

    NounWordEntity getNounWordEntity() const;
};

#endif