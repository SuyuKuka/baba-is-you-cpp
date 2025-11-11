#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main(int argc, char* argv[]) {
    RenderWindow app(VideoMode(1280, 720), "BABA IS YOU");
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
