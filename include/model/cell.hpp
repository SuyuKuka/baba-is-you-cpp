#ifndef CELL_HPP
#define CELL_HPP
#include <vector>
#include "model/entity.hpp"
using namespace std;

class Cell {
public:
    vector<Entity*> entities;
};

#endif