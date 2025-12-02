#include <iostream>
#include <SFML/Graphics.hpp>
#include "controller/keyboardListener.hpp"
#include "view/mainView.hpp"
#include "model/mainModel.hpp"
using namespace sf;

int main() {
    MainView view;
    MainModel game;
    while (view.isOpen()) {         
        if (view.getCurrentState() == AppState::Menu) {
            cout << "Menu" << endl;
            view.run();
        } else if (view.getCurrentState() == AppState::Game) {
            cout << "Game" << endl;
            Map map = MapParser::loadMap(view.getPath());
            KeyboardListener& keyboardListener = KeyboardListener::getInstance();
            game.init(&map);
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
                    game.update(pos, keyboardListener.isPulling());
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
            }
        }
    }  
    return EXIT_SUCCESS;
}