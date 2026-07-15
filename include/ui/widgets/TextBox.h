#pragma once
#include "ui/TextWidget.h"
#include <SFML/Graphics.hpp>

class TextBox : public TextWidget {
    public:
        TextBox() = default;

        bool handleEvent(const sf::Event& e, UIContext& ctx) override;
        void update(float, UIContext&) override {}
        void draw(sf::RenderTarget& t, const UIContext& ctx) const override;
};