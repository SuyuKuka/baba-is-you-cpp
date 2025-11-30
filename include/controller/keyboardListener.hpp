#ifndef _KEYBOARD
#define _KEYBOARD
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "model/map/map.hpp"
#include "model/map/position.hpp"
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
    sf::Clock repeatClock; 
    sf::Time initialDelay = sf::milliseconds(100); 
    sf::Time repeatRate = sf::milliseconds(100); 
    
    sf::Keyboard::Key lastMovedKey = sf::Keyboard::Key::Unknown;
    bool firstMoveExecuted = false;

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

    void handleMove();

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

    const Keyboard::Key& getLastKeyPressed() const {
        return lastMovedKey;
    }
};

ostream& operator<<(ostream& out, const KeyboardListener& keyboardListener);

#endif
