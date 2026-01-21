#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class State;

/*
    Aufgabe:;

    Verwaltet alle States
    Zentrale Steuerung, welcher Programmzustand gerade gilt

    Warum Stack?
    der oberste State ist aktiv
    darunter liegende States können "pausiert" bleiben

    Aufgaben:
    push(State) -> neuen Zustand aktivieren
    pop() -> aktuellen beenden
    clear() -> alles schlie0en
    weiterleitung:
        events / updates / rendering
*/

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

        bool empty() const { return m_states.empty(); }
};