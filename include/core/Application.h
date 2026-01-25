#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "state/StateStack.h"
#include "state/EmptyState.h"
#include "state/MainMenuState.h"

/*
    Tasks:

    - Initializes the window (sf::RenderWindow)
    - only class that interacts directly with the window
    - Runs the main loop
      > Process events
      > Update logic
      > Render
    - Manages timing (delta time)

    Function:
    - Workflow + Infrastructure
*/

class Application {
    private:
        sf::RenderWindow m_app; // window object
        sf::Clock m_clock;      // for delta time
        sf::Font m_font;        // standart Font
        
        StateStack m_states;    // manages the states (scenes)

        void processEvents() { 
            while (const auto e = m_app.pollEvent()) {
                if (e->is<sf::Event::Closed>())
                    m_app.close();

                if (e->is<sf::Event::Resized>()) {
                    const auto* r = e->getIf<sf::Event::Resized>();
                    if (r->size.x == 0 || r->size.y == 0) continue;

                    m_app.setView(sf::View(sf::FloatRect({0.f, 0.f},
                        {(float)r->size.x, (float)r->size.y})));

                    m_states.onResize(r->size);   // <-- State bekommt neue Größe
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

            if (!m_font.openFromFile("../assets/Montserrat/static/Montserrat-Regular.ttf")) //Load Standart font
                throw std::runtime_error("Font not found");

            m_states.push(std::make_unique<MainMenuState>(m_states, m_font, m_app.getSize())); // MainMenuState as start scene
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