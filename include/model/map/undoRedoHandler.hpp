#ifndef _UNDO_REDO_HANDLER
#define _UNDO_REDO_HANDLER
#include <iostream>
#include <model/map/direction.hpp>
#include "model/entity/entityState.hpp"
#include <stack>
#include <queue>
using namespace std;

class UndoRedoHandler {
    private:
    stack<vector<EntityState>> undo;
    stack<vector<EntityState>> redo;
    stack<Direction> undoDirection;
    stack<Direction> redoDirection;
    public:
    UndoRedoHandler();
    ~UndoRedoHandler();
    vector<EntityState> undoStep();
    vector<EntityState> redoStep();
    void emptyRedo();
    void addUndoState(const EntityState& entity);
    void next();
    void addUndoDirection(const Direction& lastDirection);
    Direction popUndoDirection();
    Direction popRedoDirection();
    void removeTopEmpty();
};

#endif