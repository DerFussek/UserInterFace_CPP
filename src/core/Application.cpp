#include "core/Application.h"
#include "state/EmptyState.h"
#include "state/MainMenuState.h"

Application::Application(sf::Vector2u size, std::string name)
    : m_app(sf::VideoMode{size, 32}, name)
{
    m_app.setVerticalSyncEnabled(true);

    if (!m_font.openFromFile("../assets/Montserrat/static/Montserrat-Regular.ttf")) // Load standard font
        throw std::runtime_error("Font not found");

    m_states.push(std::make_unique<MainMenuState>(m_states, m_font, m_app.getSize())); // MainMenuState as start scene
}

void Application::processEvents() {
    while (const auto e = m_app.pollEvent()) {
        if (e->is<sf::Event::Closed>())
            m_app.close();

        if (e->is<sf::Event::Resized>()) {
            const auto* r = e->getIf<sf::Event::Resized>();
            if (r->size.x == 0 || r->size.y == 0) continue;

            m_app.setView(sf::View(sf::FloatRect({0.f, 0.f},
                {(float)r->size.x, (float)r->size.y})));

            m_states.onResize(r->size);   // State bekommt neue Größe
        }

        if (auto* s = m_states.top()) s->handleEvent(*e);
    }
}

void Application::update(float dt) {
    m_states.update(dt);
}

void Application::render() {
    m_app.clear();
    m_states.render(m_app);
    m_app.display();
}

void Application::run() {
    while (m_app.isOpen()) {
        processEvents();
        const float dt = m_clock.restart().asSeconds();
        update(dt);
        render();
    }
}
