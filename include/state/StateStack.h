#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

/*
    Task:

    Manages all states
    Central control over the currently active program state

    Why a Stack?
    The top-level state is active
    States underneath can remain "paused"

    Tasks:
    push(State) > Activate a new state
    pop()       > Terminate the current state
    clear()     > Cloase all states

    Delegation (Forwarding):
    Events / Updates / Rendering

*/

class State;

class StateStack {
    private:
        std::vector<std::unique_ptr<State>> m_states;
    
    public:
        void push(std::unique_ptr<State> s);
        void pop();
        void clear();

        State* top();

        void handleEvent(const sf::Event& e);
        void update(float dt);
        void render(sf::RenderTarget& target);

        void onResize(sf::Vector2u newSize);

        bool empty() const { return m_states.empty(); }
};