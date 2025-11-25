#ifndef CELL_HPP
#define CELL_HPP
#include <vector>
#include <algorithm>
#include "model/entity.hpp"
using namespace std;

class Cell {
private :
    vector<Entity*> entities;
public:
    vector<Entity*> getEntities() const {
        return entities;
    }

    void addEntity(Entity* entity) {
        entities.push_back(entity);
    }

    void removeEntity(Entity* entity) {
        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    }

    bool isEmpty() const {
        return entities.empty();
    }

    void clear() {
        entities.clear();
    }
};

#endif