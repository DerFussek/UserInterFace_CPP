#pragma once
#include "state/State.h"

class EmptyState final : public State {
public:
    explicit EmptyState(StateStack& stack) : State(stack) {}

    void handleEvent(const sf::Event&) override {}
    void update(float) override {}

    void render(sf::RenderTarget& target) override {
        sf::RectangleShape r({200.f, 120.f});
        r.setPosition({50.f, 50.f});
        r.setFillColor(sf::Color::Red);
        target.draw(r);
    }
};
