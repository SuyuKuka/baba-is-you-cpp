#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/mapParser.hpp"
#include "view/mainView.hpp"
using namespace sf;

int main() {
    MainView view;
    Map map = MapParser::loadMap("resources/maps/map-1.json");
    while (view.isOpen()) {
        Event event;
        while (view.pollEvent(event)) {
            if (event.type == Event::Closed) {
                view.close();
            }
        }
        view.render(map.getOccupiedCells());
    }
    return EXIT_SUCCESS;
}
