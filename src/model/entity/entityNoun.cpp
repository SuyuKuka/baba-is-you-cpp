#include "model/entity/entityNoun.hpp"

EntityNoun::EntityNoun(Position pos, int id): Entity(pos, id) { }

NounWordEntity EntityNoun::getNounWordEntity() const {
    return static_cast<NounWordEntity>(getId());
}