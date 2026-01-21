#pragma once

#include <SFML/Graphics.hpp>
#include "state/State.h"
#include "ui/UIContext.h"
#include "ui/widgets/Panel.h"
#include "ui/widgets/Label.h"
#include "ui/widgets/Button.h"
#include "ui/layout/VBoxLayout.h"

class MainMenuState : public State {
private:
    UIContext m_ui;
    Panel m_root;
    VBoxLayout m_layout;

public:
    MainMenuState(StateStack& stack, const sf::Font& font, sf::Vector2u windowSize);

    void handleEvent(const sf::Event& e) override;
    void update(float dt) override;
    void render(sf::RenderTarget& target) override;
};
