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
    stack<Direction> directionStack;
    stack<Direction> redoDirection;
    public:
    UndoRedoHandler();
    ~UndoRedoHandler();
    vector<EntityState> undoStep();
    vector<EntityState> redoStep();
    void clear();
    void emptyUndo();
    void emptyRedo();
    void emptyDirection();
    void emptyRedoDirection();
    void addUndoState(const EntityState& entity);
    void next();
    void addDirection(const Direction& lastDirection);
    Direction getDirection();
    Direction getRedoDirection();
    void removeTopEmpty();
};

#endif