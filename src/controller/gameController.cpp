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
            if (canContinue()) continue;
            computeInput(keyboardListener);
            repeatClock.restart();
        }
        update(keyboardListener, map);
    }
}

void GameController::update(KeyboardListener& keyboardListener, Map& map) {
    const vector<const Cell *>& occupied = map.getOccupiedCells();
    if (game.getRuleProcessor().babaIsYou()) {
        view.render(occupied, keyboardListener.getLastDirection());
    } else {
        view.render(occupied, keyboardListener.keyToDirection(Keyboard::Key::Unknown));
    }
    if (game.isWin()) {
        keyboardListener.clearKeyPressed();
        view.setCurrentState(AppState::Menu);
    }
}

bool GameController::canContinue() const {
    sf::Time delay = repeatRate;
    KeyboardListener& keyboardListener = KeyboardListener::getInstance();
    if (!keyboardListener.firstInput()) {
        delay = sf::Time::Zero;
    } else if (keyboardListener.getLastKeyPressed() != keyboardListener.getKeyPressed().back() 
    || repeatClock.getElapsedTime() < initialDelay) {
        delay = (keyboardListener.getLastKeyPressed() != keyboardListener.getKeyPressed().back()) ? initialDelay : repeatRate;
    }
    if (repeatClock.getElapsedTime() < delay || keyboardListener.getKeyPressed().empty()) return true;
    return false;
}

void GameController::computeInput(KeyboardListener& keyboardListener) {
    if (keyboardListener.getKeyPressed().back() == Keyboard::R) {
        keyboardListener.setLastDirection(game.undo());
        keyboardListener.setLastKey(Keyboard::R);
    } else if (keyboardListener.getKeyPressed().back() == Keyboard::T) {
        keyboardListener.setLastDirection(game.redo());
        keyboardListener.setLastKey(Keyboard::T);
    } else {
        Position pos = keyboardListener.handleMove();
        if (pos == Position(0, 0)) return;
        game.update(pos, keyboardListener.isPulling(), keyboardListener.getLastDirection());
    }
}