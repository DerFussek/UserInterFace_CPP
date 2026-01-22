#pragma once
#include <SFML/Graphics.hpp>

/*
    Purpose:
    A layout strategy used to arrange child widgets vertically within a container.

    Tasks:
    - Defines spacing rules (padding and spacing) for UI elements.
    - Automatically calculates and applies positions to widgets inside a Container.

    Functionality:
    - Vertical Alignment: Lines up widgets from top to bottom.
    - Spacing Management:
        * Padding: The internal offset between the container's border and the widgets.
        * Spacing: The vertical gap between individual widgets.
    - Decoupling: Separates the positioning logic from the Container class itself.
*/


class Container;

struct VBoxLayout {
    float padding = 12.f;
    float spacing = 10.f;

    void apply(Container& c) const;
};
