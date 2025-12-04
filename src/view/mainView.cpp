#include "view/mainView.hpp"

MainView::MainView(): app(VideoMode(1280, 720), "BABA IS YOU", Style::Titlebar | Style::Close) 
, cellWidth(floor(app.getSize().x/33.0)), cellHeight(floor(app.getSize().y/18.0)) {
    path = "";
    currentState = AppState::Menu;
    font.loadFromFile("resources/fonts/GrapeSoda.ttf");

    levels.push_back(LevelInfo({"Tutorial", "resources/maps/map-1.json"}));
    levels.push_back(LevelInfo({"Lock", "resources/maps/map-2.json"}));
    levels.push_back(LevelInfo({"Secret", "resources/maps/map-3.json"}));
}

void MainView::run() {
    while (isOpen() && currentState == AppState::Menu) {
        Event event;
        if (event.type == Event::Closed) {
            close();
        }
        if (pollEvent(event)) {
            handleEvents(event);
        }
        if (currentState == AppState::Menu) {
            menu();
        }
    }
}

void MainView::handleEvents(const Event& event) {
    if (currentState == AppState::Menu) {
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            handleMenuClick(event.mouseButton.x, event.mouseButton.y);
        }
    }
}

void MainView::handleMenuClick(int mouseX, int mouseY) {
    float startY = 200.f;
    float verticalSpacing = 80.f;
    float charSize = 50.f;
    
    Vector2f clickPos((float)mouseX, (float)mouseY);
    
    for (size_t i = 0; i < levels.size(); ++i) {
        Text levelText;
        levelText.setFont(font);
        string levelString = "Level " + to_string(i + 1) + " - " + levels[i].name;
        levelText.setString(levelString);
        levelText.setCharacterSize((unsigned int)charSize);
        
        float currentY = startY + (float)i * verticalSpacing;
        levelText.setPosition((app.getSize().x - levelText.getGlobalBounds().width) / 2.f, currentY);

        FloatRect bounds = levelText.getGlobalBounds();
        
        if (bounds.contains(clickPos)) {
            currentState = AppState::Game;
            path = levels[i].file;
        }
    }
}

void MainView::menu() {
    app.clear();

    Text titleText;
    titleText.setFont(font);
    titleText.setString("BABA IS YOU");
    titleText.setCharacterSize(80);
    titleText.setFillColor(Color::White);
    titleText.setPosition((app.getSize().x - titleText.getGlobalBounds().width) / 2.f, 50.f);
    app.draw(titleText);
    
    float startY = 200.f;
    float verticalSpacing = 80.f;
    Vector2i mousePos = Mouse::getPosition(app);
    Vector2f mousePosF((float)mousePos.x, (float)mousePos.y);
    for (size_t i = 0; i < levels.size(); ++i) {
        Text levelText;
        levelText.setFont(font);
        string levelString = "Level " + to_string(i + 1) + " - " + levels[i].name;
        levelText.setString(levelString);
        levelText.setCharacterSize(50);
        
        float currentY = startY + (float)i * verticalSpacing;
        levelText.setPosition((app.getSize().x - levelText.getGlobalBounds().width) / 2.f, currentY);
        FloatRect bounds = levelText.getGlobalBounds();
        if (bounds.contains(mousePosF)) {
            levelText.setFillColor(Color(170, 170, 255));
        } else {
            levelText.setFillColor(Color(200, 200, 255));
        }

        app.draw(levelText);
    }
    app.display();
}


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

string MainView::getPath() const {
    return path;
}

AppState MainView::getCurrentState() const {
    return currentState;
}

void MainView::setCurrentState(AppState state) {
    currentState = state;
}