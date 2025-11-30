#ifndef TEXT_OPERATOR_HPP
#define TEXT_OPERATOR_HPP
#include "model/entity/entity.hpp"

class EntityOperator: public Entity {
    private:
        const bool pullable;
    public:
        EntityOperator(Position pos, int id): Entity(pos, id, true), pullable(true) { }

        OperatorWordEntity getOperatorWordEntity() const {
            return static_cast<OperatorWordEntity>(getId());
        }

        const bool& isPullable() const override { return pullable; }
        void setIsPullable(const bool pullable) override {(void) pullable;}
    };

#endif