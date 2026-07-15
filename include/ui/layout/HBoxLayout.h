#pragma once
#include <SFML/Graphics.hpp>

/*
    Purpose: 
    A layout strategy used to arrange child widgets horizontally within a container.

    Task:
    - Defines spacing rules (padding and spacing) for UI elements
    - Automatically calculates and applies to widgets inside a Container

    Functionality:
    - Horizontal Alignment: Lines up widgets from left to right
    - Spacing Management: 
        * Padding: The internal offset between the container's border and the widgets.
        * Spacing: The horizontal gap between individual widgets.
*/

class Container;

struct HBoxLayout {
    float padding = 12.f;
    float spacing = 10.f;

    void apply(Container& c) const;
};