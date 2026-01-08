#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP
#include "controller/keyboardListener.hpp"
#include "view/mainView.hpp"
#include "model/mainModel.hpp"

class GameController {
private:
    MainView& view;
    MainModel& game;
    sf::Clock repeatClock; 
    sf::Time initialDelay = sf::milliseconds(180); 
    sf::Time repeatRate = sf::milliseconds(120); 
    bool quit = false;
    bool reset = true;

public:
    GameController(MainView& view, MainModel& game);
    ~GameController();

    /**
     * Charge les configurations de la carte.
     * Lance l'écoute d'événements clavier.
     */
    void run();

    /**
     * Met à jour mainModel et mainView
     * @param keyboardListener
     * @param map
     */
    void update(KeyboardListener& keyboardListener, Map& map);

    /**
     * Vérifie si le délai entre les actions permet d'en faire une nouvelle.
     * Sinon continue la boucle de jeu.
     */
    bool canContinue() const;

    /**
     * Selon la touche choisie, décide de l'action.
     * Undo Redo
     * move
     * @param keyboardListener
     */
    void computeInput(KeyboardListener &keyboardListener);
};

#endif