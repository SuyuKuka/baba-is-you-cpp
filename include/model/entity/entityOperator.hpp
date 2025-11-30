#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity/entity.hpp"

class EntityOperator: public Entity {
    public:
        EntityOperator(Position pos, int id): Entity(pos, id, true, true)  { }

        OperatorWordEntity getOperatorWordEntity() const {
            return static_cast<OperatorWordEntity>(getId());
        }

        bool isPullable() const override { return true; }
        void setIsPullable(const bool pullable) override {(void) pullable;}
    };

#endif