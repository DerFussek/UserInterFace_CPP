#pragma once

#include <SFML/Graphics.hpp>
#include "state/State.h"
#include "ui/UIContext.h"
#include "ui/Theme.h"
#include "ui/widgets/Panel.h"
#include "ui/widgets/Label.h"
#include "ui/widgets/Button.h"
#include "ui/layout/VBoxLayout.h"
#include "ui/layout/HBoxLayout.h"
#include "ui/widgets/TextBox.h"
#include "ui/widgets/InfoBox.h"

class MainMenuState : public State {
private:

    Theme m_theme{
        nullptr,
        22,
        sf::Color(0x2A, 0x2F, 0x33),   // textColor
        sf::Color(0x8C, 0x94, 0x91),   // panelColor
        sf::Color(0x8C, 0x94, 0x91),   // buttonIdle
        sf::Color(0x5D, 0xA5, 0xEA),   // buttonHover
        sf::Color(0x15, 0x81, 0xE8),   // buttonPressed
        sf::Color(50, 50, 50),         // buttonDisabled
        sf::Color(0x2A, 0x2F, 0x33),   // outlineColor
        2.f,
        10.f, 
        150.f
    };


    UIContext m_ui{m_theme};
    Panel m_root;
    VBoxLayout m_layout;
    sf::Vector2u m_windowSize;

public:
    MainMenuState(StateStack& stack, const sf::Font& font, sf::Vector2u windowSize);

    void handleEvent(const sf::Event& e) override;
    void update(float dt) override;
    void render(sf::RenderTarget& target) override;

    void onResize(sf::Vector2u s) override;
};
