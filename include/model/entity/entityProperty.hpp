#ifndef TEXT_PROPERTY_HPP
#define TEXT_PROPERTY_HPP
#include "model/entity/entity.hpp"

class EntityProperty: public Entity {
    public:
        EntityProperty(Position pos, int id): Entity(pos, id, true, true) { }

        PropertyWordEntity getPropertyWordEntity() const {
            return static_cast<PropertyWordEntity>(getId());
        }

        bool isPullable() const override { return true; }
        void setIsPullable(const bool pullable) override {(void) pullable;}
    };

#endif