#pragma once
#include "ui/TextWidget.h"

class Label : public TextWidget {
    public:
        Label() = default;

        bool handleEvent(const sf::Event&, UIContext&) override { return false; }
        void update(float, UIContext&) override {}
        void draw(sf::RenderTarget& t, const UIContext& ctx) const override;
};
