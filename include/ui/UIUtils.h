#pragma once
#include <SFML/Graphics.hpp>

/*
    Purpose:
    Shared utility functions for the UI subsystem.
*/

namespace ui {

inline bool pointIn(const sf::FloatRect& r, sf::Vector2f p) {
    return r.contains(p);
}

} // namespace ui
