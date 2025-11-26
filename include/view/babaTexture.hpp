#ifndef _TEXTURE
#define _TEXTURE
#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/entity/entityType.hpp"
using namespace std;
using namespace sf;

class BabaTexture {
    private:
    const string path = "resources/sprites/";

    Texture BABA_UP;
    Texture BABA_RIGHT;
    Texture BABA_LEFT;
    Texture BABA_DOWN;
    Texture BABA_TEXT;
    Texture FLAG_TEXT;
    Texture FLAG;
    Texture IS;
    Texture PULL;
    Texture PUSH;
    Texture ROCK_TEXT;
    Texture ROCK;
    Texture STOP;
    Texture WALL_TEXT;
    Texture WALL;
    Texture WIN;
    Texture YOU;

    BabaTexture();
    ~BabaTexture() = default;
    BabaTexture(const BabaTexture&) = delete;
    BabaTexture& operator=(const BabaTexture&) = delete;

    public:

    static BabaTexture& getInstance();

    /**
     * @param id l'id de l'entité.
     * @param key une touche qui est par défaut D.
     * @return Une texture const correspondant à l'entité indiquée.
     */
    const Texture& getTexture(const int id,  const Keyboard::Key key = Keyboard::Key::D) const; 
};

#endif
