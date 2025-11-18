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
            switch (event.type) {
                case Event::Closed:
                    app.close(); 
                    break;
                case Event::KeyPressed:
                    keyboardListener.handleKeyPressedAndReleased(event, true);
                    break;
                case Event::KeyReleased:
                    keyboardListener.handleKeyPressedAndReleased(event, false);
                    break;
                default : break;
            }
        }
        cout << keyboardListener << endl; 
        app.clear();
        app.display();
    }
    return EXIT_SUCCESS;
}
