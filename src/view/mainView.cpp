#include "view/mainView.hpp"

MainView::MainView(): app(VideoMode(1280, 720), "BABA IS YOU", Style::Titlebar | Style::Close) 
, cellWidth(floor(app.getSize().x/33.0)), cellHeight(floor(app.getSize().y/18.0)) { }

void MainView::render(const vector<const Cell*> occupied) {
    app.clear();
    for (const Cell* cell : occupied) {
        for (const Entity* entity : cell -> entities) {
            double px = entity -> getX() * cellWidth;
            double py = entity -> getY() * cellHeight;
            Texture texture;
            texture.loadFromFile("resources/sprites/Baba.png");
            Sprite sprite;
            sprite.setTexture(texture);
            sprite.setScale(cellWidth / sprite.getTextureRect().width,
                cellHeight / sprite.getTextureRect().height);
            sprite.setPosition(px,py);
            app.draw(sprite);
        }
    }
    app.display();
}

bool MainView::pollEvent(Event& event) {
    return app.pollEvent(event);
}


bool MainView::isOpen() const {
    return app.isOpen();
}

void MainView::close() {
    app.close();
}