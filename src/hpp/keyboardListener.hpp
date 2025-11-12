#ifndef _KEYBOARD
#define _KEYBOARD
#include <iostream>
#include <SFML/Window.hpp>
#include <vector>
using namespace std;
using namespace sf;

/**
 * @class Keyboard  
 * Classe Singleton permettant l'écoute du clavier pour les contrôles du jeu.
 */
class KeyboardListener {
    private:
    KeyboardListener() = default;
    ~KeyboardListener() = default;
    KeyboardListener(const KeyboardListener&) = delete;
    KeyboardListener& operator=(const KeyboardListener&) = delete;


    public:
    static KeyboardListener& getInstance();

    /**
     * @param event un événement contenant la touche à ajouter.  
     * @brief Ajoute la touche au vector des touches appuyées.
     */
    void handleKeyPressed(const Event& event);

    /**
     * @param event un événement contenant la touche appuyée.
     * @brief Retire la touche appuyée c'est elle est présente dans la liste.
     */
    void handleKeyReleased(const Event& event);

    /**
     * @param key la touche que l'on veut vérifier.
     * @return true si la touche est bien appuyée.
     */
    bool isKeyPressed(Keyboard::Key key) const;
};

#endif