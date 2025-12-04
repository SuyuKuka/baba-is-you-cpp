#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP
#include "controller/keyboardListener.hpp"
#include "view/mainView.hpp"
#include "model/mainModel.hpp"

class GameController {
private:
    MainView& view;
    MainModel& game;
public:
    GameController(MainView& view, MainModel& game) : view(view), game(game) {};
    ~GameController() = default;
    void run();
    void update(KeyboardListener& keyboardListener, Map& map);
};

#endif