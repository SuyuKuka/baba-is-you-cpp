#include <iostream>
#include <SFML/Graphics.hpp>
#include "hpp/mapParser.hpp"
using namespace sf;

int main(int argc, char* argv[]) {
    RenderWindow app(VideoMode(1280, 720), "BABA IS YOU");
    MapParser& mapParser = MapParser::getInstance();
    mapParser.parseConfig("resources/maps/map-2.json");
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
