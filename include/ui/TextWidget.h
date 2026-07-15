#pragma once
#include "ui/Widget.h"
#include <SFML/Graphics.hpp>

/*
    Purpose:
    Intermediate base class for widgets that display text.
    Consolidates common text-related fields and rendering helpers.

    Tasks:
    - Stores text content (sf::String) and optional character size override.
    - Provides reusable text-rendering helpers for centered and left-aligned text.

    Functionality:
    - Eliminates code duplication across Label, Button, TextBox, and InfoBox.
    - drawTextCentered: centers text both horizontally and vertically within the widget bounds.
    - drawTextLeft: left-aligns text with optional padding and vertical centering.
*/

class TextWidget : public Widget {
protected:
    sf::String m_string;
    unsigned int m_charSize = 0; // 0 => Theme default

    void drawTextCentered(sf::RenderTarget& t, const UIContext& ctx) const;
    void drawTextLeft(sf::RenderTarget& t, const UIContext& ctx,
                      float leftPad = 0.f, bool vCenter = false) const;

public:
    void setString(const sf::String& s) { m_string = s; }
    void setCharacterSize(unsigned int px) { m_charSize = px; }
};
