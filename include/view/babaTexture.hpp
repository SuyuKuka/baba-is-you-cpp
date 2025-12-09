#ifndef _TEXTURE
#define _TEXTURE
#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/entity/entityType.hpp"
#include "model/map/direction.hpp"
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
    Texture IS_TEXT;
    Texture AND_TEXT;
    Texture PULL_TEXT;
    Texture PUSH_TEXT;
    Texture ROCK_TEXT;
    Texture ROCK;
    Texture STOP_TEXT;
    Texture WALL_TEXT;
    Texture WALL;
    Texture WIN_TEXT;
    Texture YOU_TEXT;
    Texture KEY;
    Texture KEY_TEXT;
    Texture DOOR;
    Texture DOOR_TEXT;
    Texture OPEN_TEXT;
    Texture SHUT_TEXT;
    Texture * last_baba_texture;

    BabaTexture();
    ~BabaTexture() = default;
    BabaTexture(const BabaTexture&) = delete;
    BabaTexture& operator=(const BabaTexture&) = delete;

public:
    static BabaTexture& getInstance();

    /**
     * @param id l'id de l'entité.
     * @param dir une direction.
     * @return Une texture const correspondant à l'entité indiquée.
     */
    const Texture& getTexture(const int& id,  const Direction& dir); 
    void resetLastTexutre();
};

#endif
