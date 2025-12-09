#ifndef _KEYBOARD
#define _KEYBOARD
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "model/map/map.hpp"
#include "model/map/position.hpp"
#include "model/map/direction.hpp"
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
    // sf::Clock repeatClock; 
    // sf::Time initialDelay = sf::milliseconds(180); 
    // sf::Time repeatRate = sf::milliseconds(120); 
    
    sf::Keyboard::Key lastKey = sf::Keyboard::Key::Unknown;
    Direction lastDirection = Direction::EAST;
    bool firstMoveExecuted = false;

public:
    /**
     * @return L'instance du KeyboardListener.
     */
    static KeyboardListener& getInstance();

    /**
     * @param event un événement contenant la touche à ajouter.  
     * @brief Ajoute ou supprime une touche du vector des touches appuyées.
     */
    void handleKeyPressedAndReleased(const Event& event);

    Position handleMove();

    bool isPulling() const;

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

    const bool& firstInput() const;

    const Keyboard::Key& getLastKeyPressed() const;

    void clearKeyPressed() { keyPressed.clear(); }

    Direction keyToDirection(const Keyboard::Key& key);

    Keyboard::Key directionToKey(const Direction& dir);

    Direction& getLastDirection();

    void setLastDirection(const Direction& dir);
    void setLastKey(const Keyboard::Key& key);
};

ostream& operator<<(ostream& out, const KeyboardListener& keyboardListener);

#endif
