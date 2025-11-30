#ifndef CELL_HPP
#define CELL_HPP
#include <vector>
#include <algorithm>
#include "model/entity/entity.hpp"
using namespace std;

class Cell {
private :
    vector<Entity*> entities;
public:
    const vector<Entity*>& getEntities() const {
        return entities;
    }

    void deleteEntities() {
        for (Entity * e : entities) {
            delete e;
        }
        entities.clear();
    }

    void addEntity(Entity* entity) {
        entities.push_back(entity);
    }

    void removeEntity(Entity* entity) {
        entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
    }

    bool isEmpty() const {
        return entities.empty();
    }

    void clear() {
        entities.clear();
    }
};

#endif