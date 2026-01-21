#pragma once
#include <SFML/Graphics.hpp>

class Container;

struct VBoxLayout {
    float padding = 12.f;
    float spacing = 10.f;

    void apply(Container& c) const;
};
