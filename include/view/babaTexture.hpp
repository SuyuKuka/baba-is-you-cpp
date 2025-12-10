#ifndef _TEXTURE
#define _TEXTURE
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include "json.hpp"
#include "model/entity/entityType.hpp"
#include "model/map/direction.hpp"
using namespace std;
using namespace sf;
using json = nlohmann::json;

class BabaTexture {
    private:
    const string path = "resources/sprites/";
    const string texture_config = "resources/sprite-config.json";

    map<int, Texture> textures;

    Texture BABA_UP;
    Texture BABA_RIGHT;
    Texture BABA_LEFT;
    Texture BABA_DOWN;
    Texture BABA_TEXT;
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
