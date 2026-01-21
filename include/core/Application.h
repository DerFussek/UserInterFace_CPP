#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "state/StateStack.h"
#include "state/EmptyState.h"
#include "state/MainMenuState.h"


/*
Aufgaben:

Erzeugt das Fenster (sf::RenderWindow)

Führt die Hauptschleife aus
—> Events verarbeiten
—> Logik updaten
—> Rendern

Steuert das Timing (Delta-Time)

Ist die einzige Klasse, die direkt mit dem Window arbeitet


Funktion:

Ablauf + Infrastruktur
*/

class Application {
    private:
        sf::RenderWindow m_app;
        sf::Clock m_clock;
        sf::Font m_font;
        
        StateStack m_states;

        void processEvents() {
            while (const auto e = m_app.pollEvent()) {
                if (e->is<sf::Event::Closed>())
                    m_app.close();

                if (e->is<sf::Event::Resized>()) {
                    const auto s = e->getIf<sf::Event::Resized>();
                    m_app.setView(sf::View(sf::FloatRect({0.0f, 0.0f},
                                        {static_cast<float>(s->size.x), 
                                         static_cast<float>(s->size.y)})));
                }

                if (auto* s = m_states.top()) s->handleEvent(*e);
            }
        }
    
        void update(float dt) {
            m_states.update(dt);
            //TODO
            //ui.update(dt)
        }

        void render() {
            m_app.clear();

            m_states.render(m_app);
            //TODO
            //ui.draw(m_app)

            m_app.display();
        }

    public:
        Application(sf::Vector2u size, std::string name)
            : m_app(sf::VideoMode{size, 32}, name)
        {
            m_app.setVerticalSyncEnabled(true);

            if (!m_font.openFromFile("../assets/Montserrat/static/Montserrat-Regular.ttf"))
                throw std::runtime_error("Font not found");

            m_states.push(std::make_unique<MainMenuState>(m_states, m_font, m_app.getSize()));
        }


        void run() {
            while (m_app.isOpen()) {
                processEvents();
                const float dt = m_clock.restart().asSeconds();
                update(dt);
                render();
            }
        }
        
    sf::RenderWindow& app() { return m_app; }  
};