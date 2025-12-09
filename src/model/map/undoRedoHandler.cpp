#include "model/map/undoRedoHandler.hpp"

UndoRedoHandler::UndoRedoHandler() = default;
UndoRedoHandler::~UndoRedoHandler() = default;

vector<EntityState> UndoRedoHandler::undoStep() {
    if (undo.empty()) return {};
    vector<EntityState> top = undo.top();
    if (top.empty()) return {};

    for (EntityState& e : top) {
        e.loadBeforeState();
    }

    redo.push(top);
    undo.pop();

    if (!directionStack.empty()) {
        redoDirection.push(directionStack.top());
        directionStack.pop();    
    }
    
    return top;
}

vector<EntityState> UndoRedoHandler::redoStep() {
    if (redo.empty()) return {};
    vector<EntityState> top = redo.top();
    if (top.empty()) return {};

    for (EntityState& e : top) {
        e.loadAfterState();
    }

    undo.push(top);
    redo.pop();

    if (!redoDirection.empty()) {
        directionStack.push(redoDirection.top());
        redoDirection.pop();    
    }

    return top;
}

void UndoRedoHandler::clear() {
    emptyUndo();
    emptyRedo();
    emptyDirection();
    emptyRedoDirection();
}

void UndoRedoHandler::emptyUndo() {
    while(!undo.empty()) {
        undo.pop();
    }
}

void UndoRedoHandler::emptyDirection() {
    while(!directionStack.empty()) {
        directionStack.pop();
    }
}

void UndoRedoHandler::emptyRedoDirection() {
    while(!redoDirection.empty()) {
        redoDirection.pop();
    }
}


void UndoRedoHandler::emptyRedo() {
    while (!redo.empty()) {
        redo.pop();
    }
}

void UndoRedoHandler::addUndoState(const EntityState& entity) {
    vector<EntityState>& top = undo.top();
    for (EntityState& e : top) {
        if (entity.getEntity() == e.getEntity()) {
            return;
        }
    }
    top.push_back(entity);
}

void UndoRedoHandler::next() {
    undo.push({});
}

void UndoRedoHandler::removeTopEmpty() {
    if (undo.empty()) return;
    vector<EntityState>& top = undo.top();
    if (top.empty()) {
        undo.pop();
    }
}

void UndoRedoHandler::addDirection(const Direction& lastDirection) {
    directionStack.push(lastDirection);
}

Direction UndoRedoHandler::getDirection() {
    if (directionStack.empty()) return Direction::EAST;
    return directionStack.top();
}

Direction UndoRedoHandler::getRedoDirection() {
    if (directionStack.empty()) return Direction::NONE;
    return directionStack.top();
}
