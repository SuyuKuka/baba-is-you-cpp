#ifndef TEXT_NOUN_HPP
#define TEXT_NOUN_HPP
#include "model/entity/entity.hpp"

class EntityNoun: public Entity {
    private:
        const bool pullable;
    public:
        EntityNoun(Position pos, int id): Entity(pos, id, true), pullable(true) { }

        NounWordEntity getNounWordEntity() const {
            return static_cast<NounWordEntity>(getId());
        }

        const bool& isPullable() const override { return pullable; }
        void setIsPullable(const bool pullable) override {(void) pullable;}
    };

#endif