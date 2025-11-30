#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityNoun: public Entity {
    public:
        EntityNoun(Position pos, int id): Entity(pos, id, true, true)  { }

        NounWordEntity getNounWordEntity() const {
            return static_cast<NounWordEntity>(getId());
        }

        bool isPullable() const override { return true; }
        void setIsPullable(const bool pullable) override {(void) pullable;}
    };

#endif