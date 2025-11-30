#include "view/mainView.hpp"

MainView::MainView(): app(VideoMode(1280, 720), "BABA IS YOU", Style::Titlebar | Style::Close) 
, cellWidth(floor(app.getSize().x/33.0)), cellHeight(floor(app.getSize().y/18.0)) { }

void MainView::render(const vector<const Cell*>& occupied, const Keyboard::Key key) {
void MainView::render(const vector<const Cell*>& occupied, const Keyboard::Key key) {
    app.clear();
    BabaTexture& babaTexture = BabaTexture::getInstance();
    Sprite sprite;
    for (const Cell* cell : occupied) {
        for (const Entity* entity : cell -> getEntities()) {
            double px = entity -> getPosition().x * cellWidth;
            double py = entity -> getPosition().y * cellHeight;
            sprite.setTexture(babaTexture.getTexture(entity -> getId(), key));
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