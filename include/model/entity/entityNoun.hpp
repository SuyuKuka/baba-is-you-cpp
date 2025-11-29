#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity/entity.hpp"
#include "entityType.hpp"

class EntityNoun: public Entity {
public:
    EntityNoun(int x, int y, int id): Entity(x, y, id) { }

    NounWordEntity getNounWordEntity() const {
        return static_cast<NounWordEntity>(getId());
    }
};

#endif