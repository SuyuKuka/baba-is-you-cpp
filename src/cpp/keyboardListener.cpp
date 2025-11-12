#include "../hpp/keyboardListener.hpp"

KeyboardListener& KeyboardListener::getInstance() {
    static KeyboardListener instance;
    return instance;
}

void KeyboardListener::handleKeyPressed(const Event& event) {
    const Keyboard::Key key = event.key.code;
    if (key == Keyboard::W || key == Keyboard::Z || key == Keyboard::S 
        || key == Keyboard::A || key == Keyboard::Q || key == Keyboard::D 
        || key == Keyboard::LControl || key == Keyboard::RControl) {
        if (!getInstance().isKeyPressed(event.key.code)) {
            keyPressed.push_back(event.key.code);
        }
    }
}

void KeyboardListener::handleKeyReleased(const Event& event) {
    const Keyboard::Key key = event.key.code;
    if (key == Keyboard::W || key == Keyboard::Z || key == Keyboard::S 
        || key == Keyboard::A || key == Keyboard::Q || key == Keyboard::D 
        || key == Keyboard::LControl || key == Keyboard::RControl) {
        keyPressed.erase(
            remove(keyPressed.begin(), keyPressed.end(), event.key.code), keyPressed.end()
        ); 
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


ostream& operator<<(ostream& out, const KeyboardListener& keyboardListener) {
    out << "Key Pressed : { ";
    const vector<Keyboard::Key> keyPressed = keyboardListener.getKeyPressed();
    for (Keyboard::Key search : keyPressed) {
        out << search << ", ";
    }
    out << "}" << endl;
    return out;
}
