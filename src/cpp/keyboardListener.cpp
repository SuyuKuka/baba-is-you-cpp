#include "../hpp/keyboardListener.hpp"

KeyboardListener& KeyboardListener::getInstance() {
    static KeyboardListener instance;
    return instance;
}

void KeyboardListener::handleKeyPressedAndReleased(const Event& event) {
    const Keyboard::Key key = event.key.code;
    if  (isAuthorizedKey(key)) {
        if (event.type == Event::KeyPressed) {
            keyPressed.push_back(event.key.code);
        } else if (event.type == Event::KeyReleased) {
            keyPressed.erase(
                remove(keyPressed.begin(), keyPressed.end(), event.key.code), keyPressed.end()
            ); 
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
