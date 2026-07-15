#pragma once
#include "ui/TextWidget.h"
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public TextWidget {
    private:
        bool m_pressedInside = false;
        std::function<void()> m_onClick;

    public:
        Button() = default;

        void setOnClick(std::function<void()> fn) { m_onClick = std::move(fn); }

        bool handleEvent(const sf::Event& e, UIContext& ctx) override;
        void update(float, UIContext&) override {}
        void draw(sf::RenderTarget& t, const UIContext& ctx) const override;
};
