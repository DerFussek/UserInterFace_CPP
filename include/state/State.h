#pragma once
#include <SFML/Graphics.hpp>

class StateStack;

/*
    Tasks:
    - handleEvent(...) > Responds to user input
    - update(dt) > Calculate logic / update state logic
    - render(target) > draws the state components

    Function:
    Seperates program sections into clearly defined modes (State Pattern)
        e.g.:
        > MainMenuState -- Main Menu
        > GameState     -- Active Gameplay
        > PauseState    -- Pause Menu
        > SettingsState -- Settings

        Encapsulates:
        Specific input handling
        Specific logic
        Specific rendering
*/

class State {
    protected:
        StateStack& m_stack;
    
    public:
        explicit State(StateStack& stack) : m_stack(stack) {}
        virtual ~State() = default;

        virtual void handleEvent(const sf::Event& e) = 0;
        virtual void update(float dt) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
        
        virtual void onResize(sf::Vector2u newSize) { (void)newSize; }
};  