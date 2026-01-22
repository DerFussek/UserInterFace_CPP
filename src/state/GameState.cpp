#include "state/GameState.h"
#include "state/StateStack.h"

GameState::GameState(StateStack &stack, const sf::Font &font, sf::Vector2u windowSize)
: State(stack)
{
    m_ui.theme.font = &font;
    m_root.setPosition({0.f, 0.f});
    m_root.setSize({(float)windowSize.x, (float)windowSize.y});
    

    m_layout.apply(m_root);

}

void GameState::handleEvent(const sf::Event &e) {
    m_root.handleEvent(e, m_ui);
}

void GameState::update(float dt) {
    m_root.update(dt, m_ui);
}

void GameState::render(sf::RenderTarget &target) {
     m_root.draw(target, m_ui);
}

void GameState::onResize(sf::Vector2u s) {
    m_root.setSize({(float)s.x, (float)s.y});

    m_layout.apply(m_root);
    //m_hbox.apply(m_row);
}
