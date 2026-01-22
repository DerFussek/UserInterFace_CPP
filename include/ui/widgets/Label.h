#pragma once
#include "ui/Widget.h"
#include <SFML/Graphics.hpp>

class Label : public Widget {
    private:
        sf::String m_string;
        unsigned int m_charSize = 0; // 0 => Theme default

    public:
        Label() = default;

        void setString(const sf::String& s) { m_string = s; }
        void setCharacterSize(unsigned int px) { m_charSize = px; }

        bool handleEvent(const sf::Event&, UIContext&) override { return false; }
        void update(float, UIContext&) override {}
        void draw(sf::RenderTarget& t, UIContext& ctx) const override;
};
