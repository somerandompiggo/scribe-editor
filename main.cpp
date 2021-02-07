#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

int pigdig = 100;

void settings() {
    sf::Text settings;
    settings.setString("this is a test owo");
    sf::RenderWindow settingwin(sf::VideoMode(600, 400), "Scribe - Settings", sf::Style::Default);
    sf::Event event;


    // Main loop
    while (settingwin.isOpen()) {
        while (settingwin.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                settingwin.close();
            }
        }
        settingwin.draw(settings);
        settingwin.display();
    }
}

int main() {
    // create entities
    sf::RenderWindow window(sf::VideoMode(800, 600), "Scribe - Projects", sf::Style::Default);
    sf::Event event;
    sf::Font font;
    sf::Text text;
    sf::Text credits;
    sf::Thread settingsthread(&settings);
    sf::Sprite mouse;
    sf::Texture mousetex;
    sf::Text sustext;
    text.setString("default: running uncapped fps (space for cap)");
    
    // sets all entity info
    credits.setString("Scribe v0.0.1");
    
    mousetex.setSmooth(true);
    mousetex.loadFromFile("cursors/left_ptr.png");
    mouse.setTexture(mousetex);


    window.setMouseCursorVisible(false);

    font.loadFromFile("fonts/ui.ttf");

    text.setPosition(10.f, 10.f);
    text.setCharacterSize(18);
    text.setFont(font);
    text.setFillColor(sf::Color{ 252, 159, 0 });
    
    credits.setCharacterSize(16);
    credits.setFont(font);
    credits.setFillColor(sf::Color{ 252, 159, 0 });
    credits.setPosition(4.f, 580.f);
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color{ 38, 38, 38, 38 });
        window.draw(text);
        sf::Vector2i mousepos = sf::Mouse::getPosition(window);
        mouse.setPosition((float)mousepos.x, static_cast<float>(mousepos.y));
        window.draw(credits);
        window.draw(mouse);
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            mouse.move(0.f, -1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mouse.rotate(-1);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            mouse.rotate(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            text.setString("custom: running w/ 60fps cap (backspce for none)");
            window.setFramerateLimit(60);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            text.setString("custom: running uncapped fps (space for cap)");
            window.setFramerateLimit(0);
        }
    }
return 0;
}