#include "controller/keyboardListener.hpp"

KeyboardListener& KeyboardListener::getInstance() {
    static KeyboardListener instance;
    return instance;
}

void KeyboardListener::handleKeyPressedAndReleased(const Event& event) {
    const Keyboard::Key key = event.key.code;
    if (isAuthorizedKey(key)) {
        if (event.type == Event::KeyPressed && !isKeyPressed(key)) {
            keyPressed.push_back(event.key.code);
        } else if (event.type == Event::KeyReleased) {
            keyPressed.erase(
                remove(keyPressed.begin(), keyPressed.end(), event.key.code), keyPressed.end()
            ); 
        }
    }
}

Position KeyboardListener::handleMove() {
    if (keyPressed.empty()) {
        firstMoveExecuted = false;
        lastKey = sf::Keyboard::Key::Unknown;
        return Position(0, 0);
    }

    sf::Keyboard::Key currentKey = keyPressed.back(); 

    Position pos;
    if (currentKey == Keyboard::Up || currentKey == Keyboard::Z || currentKey == Keyboard::W) {
        pos.y = -1;
    } else if (currentKey == Keyboard::Down || currentKey == Keyboard::S) {
        pos.y = 1;
    } else if (currentKey == Keyboard::Left || currentKey == Keyboard::Q || currentKey == Keyboard::A) {
        pos.x = -1;
    } else if (currentKey == Keyboard::Right || currentKey == Keyboard::D) {
        pos.x = 1;
    }

    if (pos.x != 0 || pos.y != 0) {
        //repeatClock.restart();
        firstMoveExecuted = true;
        lastKey = currentKey;
        lastDirection = keyToDirection(lastKey);
        return pos;
    }
    return Position(0, 0);
}

bool KeyboardListener::isPulling() const {
    return (isKeyPressed(Keyboard::LControl) || isKeyPressed(Keyboard::RControl));
}

bool KeyboardListener::isKeyPressed(const Keyboard::Key key) const {
    for (Keyboard::Key search : keyPressed) {
        if (key == search) {
            return true;
        }
    }
    return false;
}

const vector<Keyboard::Key>& KeyboardListener::getKeyPressed() const {
    return keyPressed;
}

bool KeyboardListener::isAuthorizedKey(const Keyboard::Key& key) const {
    return key == Keyboard::Up || key == Keyboard::Z || key == Keyboard::W
        || key == Keyboard::Down|| key == Keyboard::S
        || key == Keyboard::Left || key == Keyboard::Q || key == Keyboard::A 
        || key == Keyboard::Right|| key == Keyboard::D 
        || key == Keyboard::LControl || key == Keyboard::RControl
        || key == Keyboard::R || key == Keyboard::T;
}

Direction KeyboardListener::keyToDirection(const Keyboard::Key& key) {
    if (key == Keyboard::Up || key == Keyboard::Z || key == Keyboard::W) {
        return Direction::NORTH;
    } else if (key == Keyboard::Down|| key == Keyboard::S) {
        return Direction::SOUTH;
    } else if (key == Keyboard::Left || key == Keyboard::Q || key == Keyboard::A) {
        return Direction::WEST;
    } else if (key == Keyboard::Right|| key == Keyboard::D) {
        return Direction::EAST;
    } else {
        return Direction::NONE;
    }
}

Direction& KeyboardListener::getLastDirection() {
    return lastDirection;
}

const bool& KeyboardListener::firstInput() const {
    return firstMoveExecuted;
}

const Keyboard::Key& KeyboardListener::getLastKeyPressed() const {
    return lastKey;
}

void KeyboardListener::setLastDirection(const Direction& dir) {
    lastDirection = dir;
}

void KeyboardListener::setLastKey(const Keyboard::Key& key) {
    lastKey = key;
}


ostream& operator<<(ostream& out, const KeyboardListener& keyboardListener) {
    out << "Key Pressed : { ";
    const vector<Keyboard::Key> keyPressed = keyboardListener.getKeyPressed();
    for (Keyboard::Key search : keyPressed) {
        out << search << ", ";
    }
    out << "}" << endl;
    return out;
}
