
#include <SFML/Graphics.hpp>
#include "core/Application.h"         
#include "state/StateStack.h"


int main() {
    Application app(sf::Vector2u{800u, 600u}, "App");
    app.run();
}
