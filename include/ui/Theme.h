#pragma once
#include <SFML/Graphics.hpp>

struct Theme {
    const sf::Font* font = nullptr;

    unsigned int fontSize = 22;

    sf::Color textColor         = sf::Color::White;
    sf::Color panelColor        = sf::Color(30, 30, 30);
    sf::Color buttonIdle        = sf::Color(60, 60, 60);
    sf::Color buttonHover       = sf::Color(90, 90, 90);
    sf::Color buttonPressed     = sf::Color(120, 120, 120);
    sf::Color buttonDisabled    = sf::Color(50, 50, 50);
    sf::Color outlineColor      = sf::Color(140, 140, 140);

    float outlineThickness = 2.f;
    float padding = 12.f;
    float spacing = 10.f;
};