#pragma once
#include "ui/Container.h"

class Panel : public Container {
public:
    bool handleEvent(const sf::Event& e, UIContext& ctx) override { return Container::handleEvent(e, ctx); }
    void update(float dt, UIContext& ctx) override { Container::update(dt, ctx); }
    void draw(sf::RenderTarget& t, UIContext& ctx) const override;
};
