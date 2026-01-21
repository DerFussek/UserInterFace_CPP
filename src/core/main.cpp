// src/core/main.cpp  (minimaler Test)
#include <SFML/Graphics.hpp>
#include "core/Application.h"          // deine Application
#include "state/StateStack.h"

// TODO: passe an, wie du Application/StateStack aktuell integriert hast.

int main() {
    Application app(sf::Vector2u{800u, 600u}, "App");
    app.run();
}
