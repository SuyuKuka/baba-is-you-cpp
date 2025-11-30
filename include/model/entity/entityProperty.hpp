#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity/entity.hpp"

class EntityProperty: public Entity {
    private:
        const bool pullable;
    public:
        EntityProperty(Position pos, int id): Entity(pos, id, true), pullable(true) { }

        PropertyWordEntity getPropertyWordEntity() const {
            return static_cast<PropertyWordEntity>(getId());
        }

        const bool& isPullable() const override { return pullable; }
        void setIsPullable(const bool pullable) override {(void) pullable;}
    };

#endif