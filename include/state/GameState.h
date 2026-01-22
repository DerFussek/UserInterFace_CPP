#pragma once

#include <SFML/Graphics.hpp>
#include "state/State.h"
#include "ui/UIContext.h"
#include "ui/Theme.h"
#include "ui/widgets/Panel.h"
#include "ui/widgets/Label.h"
#include "ui/widgets/Button.h"
#include "ui/layout/VBoxLayout.h"

class GameState : public State {
    private: 
        Theme m_theme{
            nullptr,
            22,
            sf::Color(0x2A, 0x2F, 0x33),   // textColor
            sf::Color(0x2A, 0x2F, 0x33),
            sf::Color(0x8C, 0x94, 0x91),   // panelColor
            sf::Color(0x5D, 0xA5, 0xEA),   // buttonIdle
            sf::Color(0x15, 0x81, 0xE8),   // buttonHover
            sf::Color(50, 50, 50),        // buttonPressed
            sf::Color(0x2A, 0x2F, 0x33),   // outlineColor
            2.f,
            12.f, 
            10.f
        };

        UIContext m_ui{m_theme, nullptr, nullptr};
        Panel m_root;
        VBoxLayout m_layout;

    public:
        GameState(StateStack& stack, const sf::Font& font, sf::Vector2u windowSize);

        void handleEvent(const sf::Event& e) override;
        void update(float dt) override;
        void render(sf::RenderTarget& target) override;

        void onResize(sf::Vector2u s) override;
};