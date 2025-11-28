#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/mapParser.hpp"
#include "controller/keyboardListener.hpp"
#include "view/mainView.hpp"
using namespace sf;

int main() {
    MainView view;
    Map map = MapParser::loadMap("resources/maps/map-1.json");
    KeyboardListener& keyboardListener = KeyboardListener::getInstance(map);
    while (view.isOpen()) {
        Event event;
        while (view.pollEvent(event)) {
            if (event.type == Event::Closed) {
                map.clear();
                view.close();
                break;
            } else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
                keyboardListener.handleKeyPressedAndReleased(event);
            }
            keyboardListener.handleMove();
            map.getRuleEngine().updateRules();
            view.render(map.getOccupiedCells());
        }
    }
    return EXIT_SUCCESS;
}
