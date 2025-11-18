#ifndef _KEYBOARD
#define _KEYBOARD
#include <iostream>
#include <SFML/Window.hpp>
#include <vector>
using namespace std;
using namespace sf;

/**
 * @class KeyboardListener  
 * @brief Singleton permettant l'écoute du clavier pour les contrôles du jeu.
 */
class KeyboardListener {
    private:
    KeyboardListener() = default;
    ~KeyboardListener() = default;
    KeyboardListener(const KeyboardListener&) = delete;
    KeyboardListener& operator=(const KeyboardListener&) = delete;
    vector<Keyboard::Key> keyPressed;

    public:
    /**
     * @return L'instance du KeyboardListener.
     */
    static KeyboardListener& getInstance();

    /**
     * @param event un événement contenant la touche à ajouter.  
     * @param isPressed true si la touche est appuyée, false sinon.
     * @brief Ajoute ou supprime une touche du vector des touches appuyées.
     */
    void handleKeyPressedAndReleased(const Event& event, const bool isPressed);

    /**
     * @param key la touche que l'on veut vérifier.
     * @return true si la touche est bien appuyée.
     */
    bool isKeyPressed(const Keyboard::Key key) const;

    /**
     * @return Le vector des touches appuyées.
     */
    const vector<Keyboard::Key>& getKeyPressed() const;
};

ostream& operator<<(ostream& out, const KeyboardListener& keyboardListener);

#endif
