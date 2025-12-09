#include <iostream>
#include <SFML/Graphics.hpp>
#include "view/mainView.hpp"
#include "model/mainModel.hpp"
#include "controller/gameController.hpp"
using namespace sf;

int main() {
    MainView view;
    MainModel game;
    GameController gameController = GameController(view, game);
    while (view.isOpen()) {         
        if (view.getCurrentState() == AppState::Menu) {
            cout << "Menu" << endl;
            view.run();
        } else if (view.getCurrentState() == AppState::Game) {
            cout << "Game" << endl;
            view.resetLastTexture();
            gameController.run();
        }
    }  
    return EXIT_SUCCESS;
}