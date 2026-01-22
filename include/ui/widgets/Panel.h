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
    bool handleEvent(const sf::Event& e, UIContext& ctx) override { return Container::handleEvent(e, ctx); }
    void update(float dt, UIContext& ctx) override { Container::update(dt, ctx); }
    void draw(sf::RenderTarget& t, UIContext& ctx) const override;
};
