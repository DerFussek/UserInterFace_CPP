#pragma once
#include "ui/Widget.h"
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public Widget {
    private:
        sf::String m_string;
        unsigned int m_charSize = 0;
        bool m_pressedInside = false;
        std::function<void()> m_onClick;

    public:
        Button() = default;

        void setString(const sf::String& s) { m_string = s; }
        void setCharacterSize(unsigned int px) { m_charSize = px; }
        void setOnClick(std::function<void()> fn) { m_onClick = std::move(fn); }

        bool handleEvent(const sf::Event& e, UIContext& ctx) override;
        void update(float, UIContext&) override {}
        void draw(sf::RenderTarget& t, UIContext& ctx) const override;
};
