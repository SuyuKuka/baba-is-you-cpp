#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/map/mapParser.hpp"
#include "controller/keyboardListener.hpp"
#include "view/mainView.hpp"
using namespace sf;

int main() {
    MainView view;
    Map map = MapParser::loadMap("resources/maps/map-2.json");
    KeyboardListener& keyboardListener = KeyboardListener::getInstance(map);
    while (view.isOpen()) {
        Event event;
        if (view.pollEvent(event)) {
            if (event.type == Event::Closed) {
                view.close();
                break;
            } else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
                keyboardListener.handleKeyPressedAndReleased(event);
            }
            keyboardListener.handleMove();
            view.render(map.getOccupiedCells());
        }
    }
    return EXIT_SUCCESS;
}
