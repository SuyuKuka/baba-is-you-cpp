#ifndef _KEYBOARD
#define _KEYBOARD
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "model/map.hpp"
using namespace std;
using namespace sf;

/**
 * @class KeyboardListener  
 * @brief Singleton permettant l'écoute du clavier pour les contrôles du jeu.
 */
class KeyboardListener {
private:
    Map& map; 
    KeyboardListener(Map& map) : map(map) {};
    ~KeyboardListener() = default;
    KeyboardListener(const KeyboardListener&) = delete;
    KeyboardListener& operator=(const KeyboardListener&) = delete;
    vector<Keyboard::Key> keyPressed;

public:
    /**
     * @return L'instance du KeyboardListener.
     */
    static KeyboardListener& getInstance(Map& map);

    /**
     * @param event un événement contenant la touche à ajouter.  
     * @brief Ajoute ou supprime une touche du vector des touches appuyées.
     */
    void handleKeyPressedAndReleased(const Event& event);

    void handleMove(const Event& event);

    /**
     * @param key la touche que l'on veut vérifier.
     * @return true si la touche est bien appuyée.
     */
    bool isKeyPressed(const Keyboard::Key key) const;

    /**
     * @return Le vector des touches appuyées.
     */
    const vector<Keyboard::Key>& getKeyPressed() const;

    /**
     * @return True si la touche est une touche autorisée.
     */
    bool isAuthorizedKey(const Keyboard::Key& key) const;
};

ostream& operator<<(ostream& out, const KeyboardListener& keyboardListener);

#endif
