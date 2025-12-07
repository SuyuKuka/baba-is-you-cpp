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
    redoDirection.push(undoDirection.top());
    undoDirection.pop();
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
    undoDirection.push(redoDirection.top());
    redoDirection.pop();
    return top;
}

void UndoRedoHandler::clear() {
    emptyUndo();
    emptyRedo();
    emptyDirection();
}

void UndoRedoHandler::emptyUndo() {
    while(!undo.empty()) {
        undo.pop();
    }
}

void UndoRedoHandler::emptyDirection() {
    while(!undoDirection.empty()) {
        undoDirection.pop();
    }

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

void UndoRedoHandler::addUndoDirection(const Direction& lastDirection) {
    undoDirection.push(lastDirection);
}

Direction UndoRedoHandler::popUndoDirection() {
    if (undoDirection.empty()) return Direction::EAST;
    if (redoDirection.empty()) return Direction::NONE;
    return redoDirection.top();
}

Direction UndoRedoHandler::popRedoDirection() {
    if (undoDirection.empty()) return Direction::NONE;
    return undoDirection.top();
}
