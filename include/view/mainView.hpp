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
    
    /**
     * Écoute les événements du menu.
     * @param event
     */
    void handleEvents(const Event& event);

    /**
     * S'occupe des mouvements et actions la souris.
     * @param mouseX
     * @param mouseY
     */
    void handleMenuClick(int mouseX, int mouseY);
    
    /**
     * Lance le menu.
     */
    void run();

    /**
     * Affiche le menu.
     */
    void menu();

    /**
     * Affiche les sprites.
     * @param occupied les cellues occupées.
     * @param dir la direction du joueur.
     */
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