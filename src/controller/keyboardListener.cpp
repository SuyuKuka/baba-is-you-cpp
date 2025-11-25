#include "controller/keyboardListener.hpp"

KeyboardListener& KeyboardListener::getInstance(Map& map) {
    static KeyboardListener instance(map);
    return instance;
}

// 73 = up, 71 = left, 74 = down, 72 = right
// 25 = z, 16 = q, 18 = s, 3 = d
// 22 = w, 0 = a
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

void KeyboardListener::handleMove(const Event& event) {
    for (const auto& key : keyPressed) {
        if (event.key.code == Keyboard::Up || event.key.code == Keyboard::Z || event.key.code == Keyboard::W) {
            map.move(0, -1);
        } else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S) {
            map.move(0, 1);
        } else if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Q || event.key.code == Keyboard::A) {
            map.move(-1, 0);
        } else if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D) {
            map.move(1, 0);
        }
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
