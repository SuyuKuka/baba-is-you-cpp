#include "controller/keyboardListener.hpp"

KeyboardListener& KeyboardListener::getInstance(Map& map) {
    static KeyboardListener instance(map);
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

void KeyboardListener::handleMove() {
    if (keyPressed.empty()) {
        firstMoveExecuted = false;
        lastMovedKey = sf::Keyboard::Key::Unknown;
        return;
    }

    sf::Keyboard::Key currentKey = keyPressed.back(); 

    sf::Time delay = repeatRate;
    if (!firstMoveExecuted) {
        delay = sf::Time::Zero;
    } else if (lastMovedKey != currentKey || repeatClock.getElapsedTime() < initialDelay) {
        delay = (lastMovedKey != currentKey) ? initialDelay : repeatRate;
    }

    if (repeatClock.getElapsedTime() < delay) {
        return;
    }

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
        map.update(pos);
        
        repeatClock.restart();
        firstMoveExecuted = true;
        lastMovedKey = currentKey;
    }
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
        || key == Keyboard::LControl || key == Keyboard::RControl;
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
