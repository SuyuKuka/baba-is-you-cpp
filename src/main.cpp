#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/mapParser.hpp"
using namespace sf;

int main() {
    RenderWindow app(VideoMode(1280, 720), "BABA IS YOU");
    MapParser& mapParser = MapParser::getInstance();
    mapParser.parseConfig("resources/maps/map-1.json");
    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    app.close(); break;
                default : break;
            }
        }
        app.clear();
        app.display();
    }
    return EXIT_SUCCESS;
}
