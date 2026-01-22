#pragma once
#include "state/State.h"

class EmptyState final : public State {
    public:
        explicit EmptyState(StateStack& stack) : State(stack) {}

        void handleEvent(const sf::Event&) override {}
        void update(float) override {}

        void render(sf::RenderTarget& target) override {}
};
