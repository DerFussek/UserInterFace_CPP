#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "state/StateStack.h"

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
        sf::Font m_font;        // standard font
        
        StateStack m_states;    // manages the states (scenes)

        void processEvents();
        void update(float dt);
        void render();

    public:
        Application(sf::Vector2u size, std::string name);

        void run();
        
        sf::RenderWindow& app() { return m_app; }  
};