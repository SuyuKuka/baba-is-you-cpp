#ifndef _MAIN_VIEW
#define _MAIN_VIEW

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "model/map/cell.hpp"
#include "model/entity/entity.hpp"
#include "model/map/direction.hpp"
#include "view/babaTexture.hpp"
using namespace std;
using namespace sf;

enum class AppState {
    Menu,
    Game
};

struct LevelInfo {
    string name;
    string file;
};

class MainView {
private:
    RenderWindow app;
    Font font;
    AppState currentState;
    string path;
    vector<LevelInfo> levels;
    const double cellWidth;
    const double cellHeight;
public:
    MainView();
    ~MainView() = default;
    void handleEvents(const Event& event);
    void handleMenuClick(int mouseX, int mouseY);
    void run();
    void menu();
    void render(const vector<const Cell*>& occupied, const Direction dir);
    bool pollEvent(Event& event);
    bool isOpen() const;
    void close();
    string getPath() const;
    AppState getCurrentState() const;
    void setCurrentState(AppState state);
    void resetLastTexture();
};

#endif