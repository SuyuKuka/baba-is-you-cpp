#ifndef _MAIN_VIEW
#define _MAIN_VIEW

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "model/map/cell.hpp"
#include "model/entity/entity.hpp"
#include "view/babaTexture.hpp"
using namespace std;
using namespace sf;

class MainView {
    private:
    RenderWindow app;
    const double cellWidth;
    const double cellHeight;
    public:
    MainView();
    ~MainView() = default;
    void render(const vector<const Cell*>& occupied, Keyboard::Key key);
    bool pollEvent(Event& event);
    bool isOpen() const;
    void close();
};

#endif