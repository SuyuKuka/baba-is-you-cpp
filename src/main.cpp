#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/mapParser.hpp"
using namespace sf;

int main() {
    RenderWindow app(VideoMode(1280, 720), "BABA IS YOU");
    Map map = MapParser::loadMap("resources/maps/map-1.json");
    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed) {
                app.close();
            } else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
                keyboardListener.handleKeyPressedAndReleased(event);
            }
        }
        cout << keyboardListener << endl; 
        app.clear();
        app.display();
    }
    return EXIT_SUCCESS;
}
