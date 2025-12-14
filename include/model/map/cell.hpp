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
    const vector<Entity*>& getEntities() const;
    void deleteEntities();
    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    bool isEmpty() const;
    size_t hasNounEntity() const;
    size_t hasOperatorEntity() const;
    size_t hasPropertyEntity() const;
    bool isIS() const;
};

#endif