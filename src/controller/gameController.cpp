#include "controller/gameController.hpp"

GameController::GameController(MainView& view, MainModel& game) : view(view), game(game) { }

GameController::~GameController() = default;

void GameController::run() {
    Map* map = nullptr;
    KeyboardListener& keyboardListener = KeyboardListener::getInstance();
    while (view.getCurrentState() == AppState::Game) {
        if (reset) {
            delete map;
            map = new Map(MapParser::loadMap(view.getPath()));
            game.init(map);
            reset = false;
            view.resetLastTexture();
        }
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
            if (quit) {
                view.setCurrentState(AppState::Menu);
                quit = false;
                reset = true;
                break;
            }
        }
        if (map) {
            update(keyboardListener, *map); 
        }
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
    if (repeatClock.getElapsedTime() < delay) return true;
    return false;
}

void GameController::computeInput(KeyboardListener& keyboardListener) {
    if (keyboardListener.getKeyPressed().empty()) return;
    if (keyboardListener.getKeyPressed().back() == Keyboard::R) {
        keyboardListener.setLastDirection(game.undo());
        keyboardListener.setLastKey(Keyboard::R);
        repeatClock.restart();
    } else if (keyboardListener.getKeyPressed().back() == Keyboard::T) {
        keyboardListener.setLastDirection(game.redo());
        keyboardListener.setLastKey(Keyboard::T);
        repeatClock.restart();
    } else {
        Position pos = keyboardListener.handleMove();
        if (pos == Position(0, 0)) return;
        if (pos == Position(-20, -20)) reset = true;
        if (pos == Position(-10, -10)) quit = true;
        game.update(pos, keyboardListener.isPulling(), keyboardListener.getLastDirection());
        repeatClock.restart();
    }
    return;
}