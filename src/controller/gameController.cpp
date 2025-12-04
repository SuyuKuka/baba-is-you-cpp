#include "controller/gameController.hpp"

void GameController::run() {
    Map map = MapParser::loadMap(view.getPath());
    KeyboardListener& keyboardListener = KeyboardListener::getInstance();
    game.init(&map);
    update(keyboardListener, map);
    while (view.getCurrentState() == AppState::Game) {
        Event event;
        if (view.pollEvent(event)) {
            if (event.type == Event::Closed) {
                view.close();
                break;
            } else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
                keyboardListener.handleKeyPressedAndReleased(event);
            }
            Position pos = keyboardListener.handleMove();
            if (pos == Position(0, 0)) {
                continue;
            }
            game.update(pos, keyboardListener.isPulling());
            update(keyboardListener, map);
        }
    }
}

void GameController::update(KeyboardListener& keyboardListener, Map& map) {
    const vector<const Cell *>& occupied = map.getOccupiedCells();
    if (game.getRuleProcessor().babaIsYou()) {
        view.render(occupied, keyboardListener.getLastKeyPressed());
    } else {
        view.render(occupied, Keyboard::Unknown);
    }
    if (game.isWin()) {
        keyboardListener.clearKeyPressed();
        view.setCurrentState(AppState::Menu);
    }
}