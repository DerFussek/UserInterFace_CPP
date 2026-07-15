#pragma once
#include "ui/TextWidget.h"
#include <SFML/Graphics.hpp>

/*
    Purpose:
    A non-interactive widget that displays a styled text message with a background.
    Renamed from MessageBox to avoid collision with the Win32 MessageBox macro.

    Tasks:
    - Renders a background rectangle with outline.
    - Displays centered text using Theme settings.
*/

class InfoBox : public TextWidget {
public:
    InfoBox() = default;

    bool handleEvent(const sf::Event& e, UIContext& ctx) override;
    void update(float, UIContext&) override {}
    void draw(sf::RenderTarget& t, const UIContext& ctx) const override;
};
