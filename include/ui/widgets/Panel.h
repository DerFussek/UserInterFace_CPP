#pragma once
#include "ui/Container.h"

/*
    Purpose:
    A concrete Container implementation, typically used as a visual background or grouping element.

    Tasks:
    - Event/Logic Forwarding: Inherits and executes standard Container behavior.
    - Custom Rendering: Overrides 'draw' to provide a visual representation (e.g., a background).

    Function:
    Acts as a UI base layer or "canvas" for other widgets.
*/

class Panel : public Container {
    public:
        void draw(sf::RenderTarget& t, const UIContext& ctx) const override;
};
