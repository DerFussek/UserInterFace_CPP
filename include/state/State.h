#pragma once
#include <SFML/Graphics.hpp>

class StateStack;

/*
Aufgaben:

handleEvent(...) → reagiert auf Eingaben

update(dt) → berechnet Logik

render(target) → zeichnet sich

Funktion:
Trennung der Programmteile in klar definierte Modi
    bsp:
    MainMenuState -> Hauptmenü
    GameState --> Spiel läuft
    PauseState --> Pausenmenü
    SettingsState --> Einstellungen

    kapselt:
    eigene Eingabeverarbeitung
    eigene Logik
    eigene Darstellung
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

};  