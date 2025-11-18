#include <iostream>
#include <SFML/Graphics.hpp>
#include "hpp/keyboardListener.hpp"
using namespace sf;

int main() {
    RenderWindow app(VideoMode(1280, 720), "BABA IS YOU");
    KeyboardListener& keyboardListener = KeyboardListener::getInstance();
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
