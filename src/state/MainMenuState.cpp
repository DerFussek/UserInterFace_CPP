#include "state/MainMenuState.h"
#include "state/StateStack.h"

MainMenuState::MainMenuState(StateStack& stack,
                             const sf::Font& font,
                             sf::Vector2u windowSize)
    : State(stack)
{
    m_ui.theme.font = &font;

    m_root.setPosition({20.f, 20.f});
    m_root.setSize({
        static_cast<float>(windowSize.x) - 40.f,
        static_cast<float>(windowSize.y) - 40.f
    });

    auto& title = m_root.emplace<Label>();
    title.setString("Main Menu");
    title.setSize({0.f, 50.f});

    auto& start = m_root.emplace<Button>();
    start.setString("Start");
    start.setSize({0.f, 60.f});
    start.setOnClick([this]() {
        // TODO: push GameState
    });

    auto& exit = m_root.emplace<Button>();
    exit.setString("Exit");
    exit.setSize({0.f, 60.f});
    exit.setOnClick([this]() {
        m_stack.pop(); // beendet diesen State
    });

    m_layout.padding = m_ui.theme.padding;
    m_layout.spacing = m_ui.theme.spacing;
    m_layout.apply(m_root);
}

void MainMenuState::handleEvent(const sf::Event& e) {
    m_root.handleEvent(e, m_ui);
}

void MainMenuState::update(float dt) {
    m_root.update(dt, m_ui);
}

void MainMenuState::render(sf::RenderTarget& target) {
    m_root.draw(target, m_ui);
}
