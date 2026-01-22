#pragma once
#include <SFML/Graphics.hpp>

/*
    Prupose: 
    A layout strategy used tp arramge cjoöd wodgtes horizontally within a container.

    Task:
    - Defines spacing rules (pading and spacing) for UI elements
    - Automatically calculates and applies to widgets inside a Contaienr

    Functionality:
    - Horizontal Alignment: Lines up widgtes from left to right
    - Spacing Managment: 
        * Padding: The internal offset between the container's border and the widgets.
        * Spacing: The horizontal gap between individual widgets.
*/

class Container;

struct HBoxLayout {
    float padding = 12.f;
    float spacing = 10.f;

    void apply(Container& c) const;
};